// create by snowcat.c 12/8/1997
#include <room.h>

inherit HOCKSHOP;

void create ()
{
  set ("short", "����");
  set ("long", @LONG

�ؽֵ��������ŵ������ƣ���������һ������˸ߵĹ�̨����
̨����Ÿ��ָ����䵱�Ķ�������ǰ���ŵ��̵��ϰ壬�����
Ц�ؽӴ��ſ��ˡ�

LONG);

  set("exits", ([
        "north"   : __DIR__"jiedao96",
      ]));
  set("objects", ([
        __DIR__"npc/le"   : 1,
      ]));

  setup();
}


