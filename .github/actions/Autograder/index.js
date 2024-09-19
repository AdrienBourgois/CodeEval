const core = require('@actions/core');
const github = require('@actions/github');
const fs = require('fs');
const { exec } = require('child_process');

// Main function
async function run() {
  try {
    const tests = loadAutogradingConfig('./.github/actions/Autograder/autograding.json');

    let totalPoints = 0;
    let maxPoints = 0;

    for (const exercise of tests.exercises) {
      console.log(`Running tests for exercise: ${exercise.name}`);

      for (const test of exercise.tests) {
        console.log(`Running test: ${test.name}`);
        maxPoints += test.points;

        // Execute the .exe with the test parameters
        const result = await runTest(test);

        // If the test succeeds, award the points
        if (result.success) {
          totalPoints += test.points;
          console.log(`Test ${test.name} passed. +${test.points} points.`);
        } else {
          console.log(`Test ${test.name} failed.`);
        }
      }
    }

    // Update the check run with the final score
    await updateCheckRun(totalPoints, maxPoints);

  } catch (error) {
    core.setFailed(`Error running autograding: ${error.message}`);
  }
}

// Load the test configuration from autograding.json
function loadAutogradingConfig(path) {
  const rawData = fs.readFileSync(path);
  return JSON.parse(rawData);
}

// Execute a test by running the .exe with the given parameters
function runTest(test) {
  return new Promise((resolve) => {
    const command = `x64\\Autograder\\Exercices.exe ${test.name} ${test.input} ${test.output}`;

    exec(command, (error, stdout, stderr) => {
      if (error) {
        console.log(`Error executing test ${test.name}: ${error.message}`);
        resolve({ success: false });
      } else {
        console.log(`stdout for test ${test.name}: ${stdout.trim()}`);
        resolve({ success: true });
      }
    });
  });
}

// Update the check run on GitHub with the test results
async function updateCheckRun(totalPoints, maxPoints) {
  try {
    const token = process.env.GITHUB_TOKEN;
    if (!token) {
      core.setFailed("GitHub token not found");
      return;
    }

    const octokit = github.getOctokit(token);
    const [owner, repo] = process.env.GITHUB_REPOSITORY.split('/');
    const runId = process.env.GITHUB_RUN_ID;

    const workflowRunResponse = await octokit.rest.actions.getWorkflowRun({
      owner,
      repo,
      run_id: runId,
    });

    const checkSuiteUrl = workflowRunResponse.data.check_suite_url;
    const checkSuiteId = parseInt(checkSuiteUrl.match(/[0-9]+$/)[0], 10);

    const checkRunsResponse = await octokit.rest.checks.listForSuite({
      owner,
      repo,
      check_name: 'Autograding',
      check_suite_id: checkSuiteId,
    });

    const checkRun = checkRunsResponse.data.total_count === 1 && checkRunsResponse.data.check_runs[0];
    if (!checkRun) {
      core.setFailed('Check run not found.');
      return;
    }

    const text = `Points ${totalPoints}/${maxPoints}`;
    await octokit.rest.checks.update({
      owner,
      repo,
      check_run_id: checkRun.id,
      output: {
        title: 'Autograding',
        summary: text,
        text: JSON.stringify({ totalPoints, maxPoints }),
        annotations: [
          {
            path: '.github',
            start_line: 1,
            end_line: 1,
            annotation_level: 'notice',
            message: text,
            title: 'Autograding complete',
          },
        ],
      },
    });

  } catch (error) {
    core.setFailed(`Error updating check run: ${error.message}`);
  }
}

run();
