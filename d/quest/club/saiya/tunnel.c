inherit ROOM;

#include <ansi.h>

void create ()
{
  set ("short","ʱ�����");
  set ("long", HIR@LONG
  
    ����һ��ʱ�������ǰ�治֪����ͨ��η���
    ����ɢ����һЩ�����˵���ֵı��������������������ʹ�ù��Ķ�����
��Բ���¡���棬�̻���һЩ��ͷ��С�ˣ����Ų�ͬ�����ƣ������Щ����
����ʽ�ɡ��Ѿ������ڸ�����ϰ�ˡ�

LONG NOR);

  set("exits",([
  "north" : __DIR__"tunnel1",
  "left" : __DIR__"ufo",
  ]));
//set("objects", ([ __DIR__"" : 1, ]));
  set("outdoors", 0);
  set("no_clean_up", 1);
  setup();
}
