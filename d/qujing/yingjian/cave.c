//Cracked by Roath
//  ����֮�� ������
//  by happ@YSZZ 2000.4.3
//  /d/qujing/yingjian/xiaolu1.c

inherit ROOM;

void create ()
{
  set ("short", "�ڶ�");
  set ("long", @LONG

һ���ں������ප�����澡��Щϡ�ࡣ����Щ���õĲ�ľ��

LONG);

  set("exits", ([
        "up": __DIR__"grass",
      ]));
  setup();
}

void init()
{
     add_action("do_push","push");
}

int do_push(string arg)
{
        object me=this_player();
        if( ! arg || arg !="grass" )
                return notify_fail("��Ҫ�ƿ�ʲô?\n");
        
        set("exits/down",__DIR__"cave");
        remove_call_out("close");
        call_out("close", 5, me);
        tell_object(me,"���ƿ�һ���Ӳݣ����ⷢ����һ���ط���\n");
        return 1;
}
void close(object room)
{
        message("vision","��һ�����ְѳ��ڶ����ˡ�\n", room);
        room->delete("exits/down");
}

