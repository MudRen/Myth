//Cracked by Roath
//  ����֮�� ������
//  by happ@YSZZ 2000.4.5
//  /d/qujing/heifeng/shandao.c

inherit ROOM;
#include <ansi.h>

void create ()
{
  set ("short", "������");
  set ("long", @LONG

�����Ƿ������еĵط��������Ժ�ķ��ɾ��ǽ�غ��У����е�����
�Ϸ�����֬������ӣ�����һ�Ѱ׽�����������������Ĳ��ѣ���
�����ܲ���һ�������˵����еĵط���
LONG);

  set("exits", ([
        "north": __DIR__"dadian",
      ]));
  set("objects", ([
        __DIR__"npc/jinchi":1,
        ]));
  setup();

}
void init()
{
        add_action("do_push","knock");
 }

int do_push(string arg)
{
        object me = this_player();

        if( !arg || arg != "wall" )
                return notify_fail("��Ҫ��ʲô��\n");

        if( me->query("obstacle/hf") == "done" )
                return notify_fail("�����˰����ǽ��Ҳû�з���ʲô��\n");

        set("exits/south", __DIR__"backroom");
        message_vision(HIC"$N������ǽ��һ�ã���Ȼǽ��һ���ƶ������ﾹȻ����һ�����䡣\n"NOR,me);
        remove_call_out("close");
        call_out("close", 3, me);
        return 1;
}
void close()
{
        object room = load_object("/d/qujing/heifeng/fzroom");
        message("vision","��Ȼǽ�Զ��ĺ�£�ˡ�\n", room);
        room->delete("exits/south");
}


