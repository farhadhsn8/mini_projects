<html>
<h3>
    @if($age <= 17)
        <h2> این وبسایت مناسب سن شما نمیباشد. </h2>
    @else
        <h2>سن شما{{$age}} میباشد </h2>
    @endif

</h3>
</html>
