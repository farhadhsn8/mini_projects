@extends('warehouse_management.index')
@section('content')


    <table class="table">
        <thead>
        <tr>
            <th>نام انبار</th>
            <th>آدرس</th>
            <th>محصولات</th>
            <th>ویرایش</th>
            <th>حذف</th>


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
                    <td><a href="#" class="btn btn-warning btn-xs"> نمایش محصولات</a></td>
                    <td><a href="{{route('warehouse.show1',$w->id)}}" class="btn btn-success btn-xs"> ویرایش </a></td>
                    <td>
                        <form action="{{route('warehouse.delete',$w->id)}}" method="POST">
                            @csrf
                            @method('delete')
                            <button type="submit" class="btn btn-danger btn-xs"> حذف </button>
                        </form>
                    </td>


                </tr>
                @php
                    $i++;
                @endphp
                @endforeach
        </tbody>
    </table>
@endsection
