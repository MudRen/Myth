// created by snowcat 12/2/1997

inherit ROOM;

void create ()
{
  set ("short", "�ռ���");
  set ("long", @LONG

�ռ����ſ�ǰ��������Ƽ��ݵ������ڵȴ�����һ��һ�ε�
����ʩ�ᡣ�������м�λ�ϵĿ��������㣬�º���һ����
ľ������
    
LONG);

  set("exits", ([
        "south"    : __DIR__"jiedao2",
      ]));
  set("objects", ([
        __DIR__"npc/monk" : 1,
      ]));
  setup();
}

