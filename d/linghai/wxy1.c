
#include <ansi.h>
inherit ROOM;

void create ()
{
  set ("short", HIW"�����µ�"NOR);
  set ("long", @LONG

�������������µס��������ƣ������Ḳ��һ����紵��
���㲻�����˸�������̧ͷ��ȥ������в�ʱ����Ⱥ�ɹ���
�㿴�˿���ɫ��������ƺ�����Ҫȥ�ĵط�������һ�β��̵�·;��
LONG);

  set("outdoors", 3);
  set("exits", ([ /* sizeof() == 3 */


  "northwest":__DIR__"minghu1",
]));

  setup();
}






