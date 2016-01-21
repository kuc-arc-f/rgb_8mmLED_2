var mClient;
var mTopic="item-kuc-arc-f/device-1/rgb_led_1";

onload = function() {
	var clientId = "clientid-0121A2";
    mClient = new Paho.MQTT.Client("test.mosquitto.org", 8080, "/", clientId);
    //mClient = new Paho.MQTT.Client("192.168.10.106", 8080, "/", clientId);

	mClient.connect({
	  onSuccess:function(){
	    console.log("con_success");
	  }
	  , onFailure:function(){console.log("con_fail")}
	});
	//
	document.querySelector('#id-a-FFA500').onclick = function() {
		publish_rgb('FFA500');
	};
	document.querySelector('#id-a-d2691e').onclick = function() {
		publish_rgb('d2691e');
	};
	document.querySelector('#id-a-800000').onclick = function() {
		publish_rgb('800000');
	};
	//
	document.querySelector('#id-a-800080').onclick = function() {
		publish_rgb('800080');
	};
	document.querySelector('#id-a-008000').onclick = function() {
		publish_rgb('008000');
	};
	document.querySelector('#id-a-ffff00').onclick = function() {
		publish_rgb('ffff00');
	};
	//
	document.querySelector('#id-a-0000ff').onclick = function() {
		publish_rgb('0000ff');
	};
	document.querySelector('#id-a-00ffff').onclick = function() {
		publish_rgb('00ffff');
	};
	document.querySelector('#id-a-ffffff').onclick = function() {
		publish_rgb('ffffff');
	};
	
}
//
function publish_rgb(value){
    message = new Paho.MQTT.Message(value);
    message.destinationName = mTopic;
    mClient.send(message);
};	

