var returned;



function getData(input) {

    console.log(input);
    $.ajax({
        url: "https://api.wunderground.com/api/b3ec5ccddf40586f/geolookup/conditions/hourly/forecast/q/"
        + input + ".json"
        , dataType: "jsonp"
        , success: function (data) {
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
            var precip = data['current_observation']['precip_today_string'];
            var forecasthourly=data['hourly_forecast'];
            var hourly=new Array(36);

            for(var i =0;i<forecasthourly.length;i++){
                hourly[i]=forecasthourly[i]['FCTTIME']['civil']+" - "+forecasthourly[i]['temp']['english']+"\u00B0F ";

            }
            $("#search_loc").text(city + ", " + state+" "+zip);
            $("title").prepend(city + ", " + state + " ");
            $("#tempature").prepend(Math.round(temp_f) + "\u00B0F");
            $('#summary').text(toTitleCase(summary));
            $('#precip').text("Preciptation: " + precip);
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

$('#query').keyup(function () {

    var value = $('#query').val();
    var rExp = new RegExp(value, "i");
    $.getJSON("https://autocomplete.wunderground.com/aq?query=" + value + "&cb=?", function (data) {
        console.log(data);

        returned = data;
        var output = '<ol>';
        $.each(data.RESULTS, function (key, val) {
            if (val.name.search(rExp) != -1) {
                output += '<li>';
                output += '<a href="https://www.wunderground.com' + val.l + '" title="See results for ' + val.name + '">' + val.name + '</a>';
                output += '</li>';
            }
        });
        output += '</ol>';
        $("#searchResults").html(output);
    });
});

$("#searchResults").on("click","a",function(evt){
    evt.preventDefault();
    var jsonCity=$(this).text();
    console.log(jsonCity);
    index=$(this).index("a");
    getData(returned.RESULTS[index].zmw)
    document.getElementById("searchResults").style.display="none";
});
function toTitleCase(str){
    return str.replace(/\w+/g, function(txt){return txt.charAt(0).toUpperCase() + txt.substr(1).toLowerCase();});
}

