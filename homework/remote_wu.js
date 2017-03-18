// Current Location Scripts
$(function () {

    var status = $('#status');

    (function getGeoLocation() {
        status.text('Getting Location...');
        if (navigator.geolocation) {
            navigator.geolocation.getCurrentPosition(function (position) {
                var lat = position.coords.latitude;
                var long = position.coords.longitude;

                // Call the getData function, send the lat and long
                getData(lat, long);

            });
        } else {
            status.text("Your browser doesn't support Geolocation or it is not enabled!");
        }

    })();

    // Get the data from the wunderground API
    function getData(lat, long) {
        $.ajax({
            url: "//api.wunderground.com/api/b3ec5ccddf40586f/geolookup/conditions/hourly/forecast/q/" + lat + "," + long + ".json",
            dataType: "jsonp",
            success: function (data) {
                console.log(data)
                var city = data['location']['city'];
                var state = data['location']['state'];
                var zip = data['location']['zip']
                var temp_f = data['current_observation']['temp_f'];
                var high = data['forecast']['simpleforecast']['forecastday']['0']['high']['fahrenheit']+"\u00B0F";
                var low = data['forecast']['simpleforecast']['forecastday']['0']['low']['fahrenheit']+"\u00B0F";
                var summary = data['current_observation']['weather'];
                var humidity = data['current_observation']['relative_humidity'];
                var winddir = data['current_observation']['wind_dir'];
                var windspeed = data['current_observation']['wind_mph'];
                var time = data['current_observation']['observation_time_rfc822'];
                var forecasthourly=data['hourly_forecast'];
                var hourly=new Array(36);
                for(var i =0;i<forecasthourly.length;i++){
                    hourly[i]=forecasthourly[i]['FCTTIME']['civil']+" - "+forecasthourly[i]['temp']['english']+"\u00B0F ";

                }
                $("#curent_loc").text(city + ", " + state+" "+zip);
                $("title").prepend(city + ", " + state + " ");
                $("#tempature").prepend(Math.round(temp_f) + "\u00B0F");
                $('#summary').text(toTitleCase(summary));
                $('#add1').text("Todays Humidity is: " + humidity);
                $('#direction').text("Wind Direction: " + winddir);
                $('#wind').text("Wind Speed: " + windspeed + " Mph");
                $('small').append(time);
                $('#time').text(hourly);
                $('#lowtemp').append("<br>"+low);
                $('#hightemp').append("<br>"+high);

                $("#cover").fadeOut(250);
            }
        });

    }

    // A function for changing a string to TitleCase
    function toTitleCase(str) {
        return str.replace(/\w+/g, function (txt) {
            return txt.charAt(0).toUpperCase() + txt.substr(1).toLowerCase();
        });
    }
});
