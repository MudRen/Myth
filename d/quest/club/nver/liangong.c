inherit ROOM;

#include <ansi.h>

void create ()
{
  set ("short","������");
  set ("long", @LONG
  
һ�����ɣ�û��һ������������������ô���԰������������������
�����豸������ȫ�����Ҳ������࣬�ط��������ɲ��õ��ģ�����
��������������

LONG);

  set("exits",([
  "east" : __DIR__"juyitang",
  ]));
//set("objects", ([ __DIR__"" : 1, ]));
  set("outdoors", 0);
  set("no_clean_up", 1);
  setup();
}