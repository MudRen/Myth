//Cracked by Roath

inherit ROOM;

void create ()
{
  set ("short", "����");
  set ("long", @LONG

����һ����ͨ����ӣ��������ӣ����ŵ��Ӷ��ƾɲ������������
ԼԼ�Ŀ��Կ���һЩģ�������룬��������Ұɡ�

LONG);

  set("exits", ([
        "north"  : __DIR__"sleeproom",

      ]));

  set("objects",([
        __DIR__"npc/lingji1.c":1,
      ]));
  	
	  set("light_up", 1);

  setup();
}
