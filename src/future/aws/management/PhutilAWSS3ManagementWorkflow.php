<?php

abstract class PhutilAWSS3ManagementWorkflow
  extends PhutilAWSManagementWorkflow {

  protected function getAWSS3BucketArguments() {
    return array(
      array(
        'name' => 'bucket',
        'param' => 'bucket',
        'help' => pht('Name of the S3 bucket to access.'),
      ),
    );
  }

  protected function newAWSFuture($future) {
    $future = parent::newAWSFuture($future);

    $argv = $this->getArgv();
    $bucket = $argv->getArg('bucket');

    $future->setBucket($bucket);

    return $future;
  }

}
