@extends('warehouse_management.index')
@section('content')


    <table class="table">
        <thead>
        <tr>
            <th>نام انبار</th>
            <th>آدرس</th>
            <th>محصولات</th>

        </tr>
        </thead>
        <tbody>

        @php
            $i=0;
        @endphp
        @foreach($warehouses as $w)

            @if($i % 2 ==0)
                <tr class="table-success">
            @endif
            @if($i % 2 ==1)
                <tr class="table-primary">
            @endif
                    <td>{{$w->name}}</td>
                    <td>{{$w->address}}</td>
                    <td><a href="#" class="btn btn-danger btn-xs"> نمایش محصولات</a></td>
                </tr>
                @php
                    $i++;
                @endphp
                @endforeach
        </tbody>
    </table>
@endsection
