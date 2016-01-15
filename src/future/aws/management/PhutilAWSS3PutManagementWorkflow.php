<?php

final class PhutilAWSS3PutManagementWorkflow
  extends PhutilAWSS3ManagementWorkflow {

  protected function didConstruct() {
    $this
      ->setName('put')
      ->setExamples(
        '**put** --key __key__')
      ->setSynopsis(pht('Upload content to S3.'))
      ->setArguments(
        array_merge(
          $this->getAWSArguments(),
          $this->getAWSS3BucketArguments(),
          array(
            array(
              'name'    => 'key',
              'param'   => 'key',
              'help'    => pht('Specify a key to upload.'),
            ),
          )));
  }

  public function execute(PhutilArgumentParser $args) {
    $key = $args->getArg('key');
    if (!strlen($key)) {
      throw new PhutilArgumentUsageException(
        pht(
          'Specify an AWS S3 object key to access with --key.'));
    }

    $future = $this->newAWSFuture(new PhutilAWSS3Future());

    echo tsprintf(
      "%s\n",
      pht('Reading data from stdin...'));

    $data = file_get_contents('php://stdin');

    $future->setParametersForPutObject($key, $data);

    $result = $future->resolve();

    echo tsprintf(
      "%s\n",
      pht('Uploaded "%s".', $key));

    return 0;
  }

}
