// Room: /d/wiz/jobroom.c

inherit ROOM;
#include <ansi.h>

void create ()
{
  set ("short","�������ȼ���");
  set ("long", @LONG
��������ʦ�Ǳ����Լ��������ȵļ��ң�ͬʱҲ�Ǵ���ʦץ����
�ĸ��ݣ�������й���������ó��������������Ĺ������ȣ����̫
��û�п�����Ĺ������ȱ��棬����ʦ�ǻ���Ϊ��û������ָ�ɹ�����
��Ҫ������Ȼ����Ҳ�п��ܻᱻ������Ѿ�������ʦ�Ĺ�����������
����֡�
LONG);

  set("exits", ([ /* sizeof() == 1 */
  "south" : WIZARD_ROOM,
  "north" : __DIR__"outjail.c",
// 20    "west"  : __DIR__"menpai_room",
]));

  setup();
//        call_other( "/obj/board/xyj_b", "???" );
//        call_other( "/obj/board/xitong_b", "???" );

}
