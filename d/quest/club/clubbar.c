inherit ROOM;

#include <ansi.h>

void create ()
{
  set ("short",HIC"���ɾ��ֲ�"NOR);
  set ("long", @LONG

���ɶ�ϲ�����Լ���һ����̳������ͨ������ϲ������̳�������ƽ
�������������ᡢ����������ˡ����ֲ�������һ�������ˣ�
�㿴�����Ӿ���Ц�����ؾ�֪�����Ƕ�ô�������ˡ�

LONG);

  set("exits",([ "down" : "/d/city/changan", ]));
  set("objects",
  ([
  __DIR__"boss" : 1,
  __DIR__"topclub" : 1,
  ]));
  set("outdoors", 0);
  set("no_clean_up", 1);
// ��ֹ��pk
// mudring Dec/10/2002
set("no_pk", 1);
  setup();
  replace_program(ROOM);
}
