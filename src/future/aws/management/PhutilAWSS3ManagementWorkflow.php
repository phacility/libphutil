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
      array(
        'name' => 'endpoint',
        'param' => 'endpoint',
        'help' => pht('Name of the AWS region to access.'),
      ),
    );
  }

}
