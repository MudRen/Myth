//Cracked by Roath
//anshi-more1.c
#include <room.h>
inherit ROOM;

// mon 6/20/99 
// since this room don't refresh, so need set limit.
int query_max_encumbrance() { return 300000; }
int query_max_items() {return 3;}

void create ()
{
	set ("short", "ͤ������");
	set ("long", @LONG

����ĵ��ͤ���µ�һ�����ң�ʮ����С������ׯ������������Ҫ��
Ʒ�ĵط������ҵ�ǽ�������ż��������ı�ʯ��������������Ȼ��
̫������ȴҲ�㹻���˿������ҵĲ����ˡ� 
LONG);

	set("exits", 
	([ //sizeof() == 4
		//"southwest" : __DIR__"juyuan",
		//"north" : __DIR__"southpool",
		"out" : __DIR__"anshi",
		//"west" : __DIR__"westway6",
	]));
	
	set("objects", 
	([ //sizeof() == 1
		//__DIR__"obj/huangtong-key" : 1,
	]));

	//set("outdoors", "wuzhuang");


	setup();
}


void init()
{
	//add_action("do_mo", "mo");

	if( query("started") != 1 )
	{
		set("started", 1);
		call_out("generate_book", 18010);//5 hours 10 seconds.
	}
}

void generate_book()
{
	object book;

	remove_call_out("generate_book");

	book = new("/d/obj/book/taiyi-book");
	book -> move(this_object());
	
	call_out("generate_book", 18010);//5 hours 10 seconds.
	//since the book will disappear after 5 hours, it's ok to generate repeatedly...

	return;
}

int clean_up()
{
	return 0;
}


