jQuery(document).ready(function ($) {
    function ajaxFromLocalJson(locationToGrab) {
        $.ajax({
            url: "../homework/weather.json",
            dataType: "json",
            success: function (data) {
                console.log(data);
                var location = data[locationToGrab]['City'];
                var state = data[locationToGrab]['State'];
                var temp_f = data[locationToGrab]['High'];
                console.log("Current temperature in " + location + " is: " + temp_f);

                var cur_location = $("#location");
                var temp = $("#temp");
                var message = $("#message");
                cur_location.html(location + ", " + state);
                temp.html(temp_f);
                message.html("Current temperature in " + location + " is: " + temp_f)
            }
        });
    }

    function ajaxFromApi() {
        $.ajax({
            url: "http://api.wunderground.com/api/c072e4e57ea2a55a/geolookup/conditions/q/ID/Rexburg.json",
            dataType: "jsonp",
            success: function (data) {
                var location = data['location']['city'];
                var state = data['location']['state'];
                var temp_f = data['current_observation']['temp_f'];
                console.log(data)

                var cur_location = $("#location");
                var temp = $("#temp");
                var message = $("#message");
                cur_location.html(location + ", " + state);
                temp.html(temp_f);
                message.html("Current temperature in " + location + " is: " + temp_f);
            }
        });
    }
    //ajaxFromLocalJson("Franklin");
    ajaxFromApi();
});
