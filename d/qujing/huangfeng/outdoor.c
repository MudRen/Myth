//Cracked by Roath

inherit ROOM;

void create ()
{
  set ("short", "ׯԺ��ǰ");
  set ("long", @LONG

��֦���裬��ʯ�Բԡ���֦�������ݣ���ʯ�Բ԰���̨������С
ӫ�����ƣ�һ��Ұ�������š�����������������ԡ���Ȫ��������
�Ű������¡���Ƨ�����ο͵�����ǰΨ��Ұ������

LONG);

  set("exits", ([
        "south"  : __DIR__"shanlu2new",
      ]));
  set("outdoors","hfd");
  setup();
}

void init()
{
  add_action("do_knock", "knock");
  add_action("do_knock", "qiao");
}
int do_knock(string arg)
{
        object me;

        me=this_player();

        if( !arg || (arg != "men" && arg != "door" && arg != "��" ) )
                return notify_fail("��Ҫ��ʲô��\n");       
        call_out("open_up", 1);
        return 1; 
}

void open_up()
{
	        object room; 

        	if( !(room = find_object(__DIR__"indoor")) )
                room = load_object(__DIR__"indoor");

                set("exits/enter", __DIR__"indoor");
		room->set("exits/out", __DIR__"outdoor");
		message("vision", "ׯԺ���ű��˴��ˡ�\n", room);
		message("vision", "ׯԺ���ű��˴��ˡ�\n", this_object());

        call_out("close_up", 100);
}

void close_up()
{
        object room;

        if( !query("exits/enter") ) return;
	message("vision", "ׯԺ�����Լ������ˡ�\n", this_object());


        if( room = find_object(__DIR__"indoor") ) 
        {
		message("vision", "ׯԺ�����Լ������ˡ�\n", room);
                room->delete("exits/out");
        }

        delete("exits/enter");
}


