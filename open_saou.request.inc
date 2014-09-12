<?php

class open_saou extends TingClientRequest implements ITingClientRequestCache {

  protected $action;
  protected $pid;
  protected $outputType;
  protected $url;
  protected $fetchLicensesByPidRequest;
  protected $fetchLisensesByUrlRequest;

  /** \brief ITingClientRequestCache::cacheEnable; Check if cache is enabled
   *
   * @return value of variable (drupal_get)
   **/
  public function cacheEnable($value = NULL) {
    $class_name = get_class($this);

    return variable_get($class_name . TingClientRequest::cache_enable, FALSE);
  }

  /** \brief set timeout of cache
   *
   * @return mixed value of variable (variable_get)
   **/
  public function cacheTimeout($value = NULL) {
    $class_name = get_class($this);

    return variable_get($class_name . TingClientRequest::cache_lifetime, '1');
  }

  public function getClientType() {
    return 'SOAPCLIENT';
  }

  public function getUrl() {
    return $this->url;
  }

  public function setUrl($value) {
    $this->url = $value;
  }

  public function getFetchLicensesByUrlRequest() {
    return $this->fetchLicensesByUrlRequest;
  }

  public function setFetchLicensesByUrlRequest($value) {
    $this->fetchLicensesByUrlRequest = $value;
  }

  public function getFetchLicensesByPidRequest() {
    return $this->fetchLicensesByPidRequest;
  }

  public function setFetchLicensesByPidRequest($value) {
    $this->fetchLicensesByPidRequest = $value;
  }

  public function setAction($value = NULL) {
    $this->action = $value;
  }

  public function getAction() {
    return $this->action;
  }

  public function setPid($value) {
    $this->pid = $value;
  }

  public function getPid() {
    return $this->pid;
  }

  public function setOutputType($value = NULL) {
    $this->outputType = $value;
  }

  public function getOutputType() {
    return $this->outputType;
  }

  public function getRequest() {
    $params = array('fetchLicensesByPidRequest', 'fetchLicensesByUrlRequest');
    foreach ($params as $parameter) {
      $getter = 'get' . ucfirst($parameter);
      if ($value = $this->$getter()) {
        $this->setParameter($parameter, $value);
      }
    }

    return $this;
  }

  // empty;
  public function processResponse(stdClass $result) {
    return $result;
  }

}