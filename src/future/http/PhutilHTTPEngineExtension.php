<?php

/**
 * Extend HTTP behavior by injecting proxies or compromising SSL.
 *
 * @task info Extension Information
 * @task config Configuring HTTP Behavior
 */
abstract class PhutilHTTPEngineExtension
  extends Phobject {


  /**
   * Human-readable name of this HTTP extension.
   *
   * @return string Human readable name.
   * @task info
   */
  abstract public function getExtensionName();


  /**
   * Return `true` to disable SSL authority verification for a URI.
   *
   * By default, certificates must be signed by a recognized authority and
   * requests fail if the host provides an invalid certificate. You can
   * override this behavior to accept any certificate (including self-signed
   * certificates). Doing this compromises the security of SSL.
   *
   * @return bool Return `true` to disable authority verification.
   * @task config
   */
  public function shouldTrustAnySSLAuthorityForURI(PhutilURI $uri) {
    return false;
  }


  /**
   * Return `true` to disable SSL hostname verification for a URI.
   *
   * By default, certificates should be signed for the correct hostname,
   * and requests fail if the host provides a certificate for a different
   * hostname. You can override this behavior to accept any certificate,
   * including certificates for a different host. Doing this compromises
   * the security of SSL.
   *
   * @return bool Return `true` to disable hostname verification.
   * @task config
   */
  public function shouldTrustAnySSLHostnameForURI(PhutilURI $uri) {
    return false;
  }


  /**
   * Return a @{class:PhutilURI} to proxy requests.
   *
   * If some or all outbound HTTP requests must be proxied, you can return
   * the URI for a proxy to use from this method.
   *
   * @return null|PhutilURI Proxy URI.
   * @task config
   */
  public function getHTTPProxyURI(PhutilURI $uri) {
    return null;
  }


  final public function getExtensionKey() {
    return $this->getPhobjectClassConstant('EXTENSIONKEY');
  }

  final public static function getAllExtensions() {
    return id(new PhutilClassMapQuery())
      ->setAncestorClass(__CLASS__)
      ->setUniqueMethod('getExtensionKey')
      ->execute();
  }

  final public static function getExtension($key) {
    $extensions = self::getAllExtensions();
    return idx($extensions, $key);
  }

  final public static function requireExtension($key) {
    $extension = self::getExtension($key);

    if (!$extension) {
      throw new Exception(
        pht(
          'No HTTP engine extension exists with extension key "%s".',
          $key));
    }

    return $extension;
  }

  final public static function buildHTTPProxyURI(PhutilURI $uri) {
    $proxy = null;
    $via = null;

    $extensions = self::getAllExtensions();
    foreach ($extensions as $extension) {
      $extension_proxy = $extension->getHTTPProxyURI($uri);

      if ($extension_proxy === null) {
        continue;
      }

      if (!($extension_proxy instanceof PhutilURI)) {
        throw new Exception(
          pht(
            'HTTP extension "%s" (of class "%s") returned an invalid '.
            'result from "%s": expected null, or an object of class "%s".',
            $extension->getExtensionName(),
            get_class($extension),
            'getHTTPProxyURI()',
            'PhutilURI'));
      }

      if ($proxy) {
        throw new Exception(
          pht(
            'Two different HTTP extensions ("%s" of class "%s" and "%s" of '.
            'class "%s") both provided a proxy URI for URI "%s". No more '.
            'than one extension may provide a proxy for any URI.',
            $extension->getExtensionName(),
            get_class($extension),
            $via->getExtensionName(),
            get_class($via),
            (string)$uri));
      }

      $proxy = $extension_proxy;
      $via = $extension;
    }

    return $proxy;
  }

}
