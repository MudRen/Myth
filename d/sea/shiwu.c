// Room: /u/rainy/sea/shiwu.c
inherit ROOM;

void create ()
{
  set ("short", "ʯ��");
  set ("long", @LONG

��԰��ͷ����һ��ʯ�ݣ����˾�ʯ���ɣ��������¿������൱��
��ʵ����ʵ�����������й���ʯ��(statue)������˫�����ƺ���
���������ֹ��
LONG);
  set("item_desc", ([ /* sizeof() == 1 */
  "status" : "ʯ�޵�ͷ���������Ť��(turn)��\n",
]));

  set("exits", ([ /* sizeof() == 3 */
  "south" : __DIR__"huayuan5",
  "north" : __DIR__"huayuan6.c",
  "west" : __DIR__"yidao.c",
]));
  set("close",1);
//      
        set("water", 1);
//  
  setup();
}

void init()
{
	add_action("do_turn", "turn");
}
int do_turn(string arg)
{
	object me,inside; 
	me=this_player();

        if ( !arg || ((arg != "statue") ))
                return notify_fail("��ҪŤ��ʲô��\n");
	message_vision("$N����Ť��ʯ�޵�ͷ����ֻ�������ǡ������졭��\n", me);


	if( !(inside=find_object(__DIR__"wunei")))
		inside=load_object(__DIR__"wunei");

	if( inside=find_object(__DIR__"wunei")) {
		if( this_object()->query("close")) {
			set("exits/enter",__DIR__"wunei");
			inside->set("exits/out",__DIR__"shiwu");
			message("vision", "ʯ�ݵ�������Ŀ��ˡ�\n", this_object());
			message("vision", "ʯ�ݵ�������Ŀ��ˡ�\n", inside);
			set("close",0);
			return 1;
		}
                delete("exits/enter");
                inside->delete("exits/out");
                message("vision", "ʯ�ݵ�������Ĺ����ˡ�\n", this_object());
                message("vision", "ʯ�ݵ�������Ĺ����ˡ�\n", inside);
                set("close",1);
                return 1;
	}
}
