// created by snowcat 12/2/1997

inherit ROOM;

void create ()
{
  set ("short", "�п�");
  set ("long", @LONG

���ɿ������������˵ظ�ɫ�˵���������������һЩ��Χ�ڽ�
����ͷ�ڽŶ���һ�����ģ�

  �������ù����ɿ������Ϲ٣�Ϊ��Ƹ��ʦ��������¡�
    ��������룬������ʵ�����꿺��������ɻġ���
    ������ȫ�����������Ի�����Ϊ�˳������ģ�����ʮ
    �����ܣ�������񣬶����ر����������ס���
        
LONG);

  set("exits", ([
        "north"    : __DIR__"jiedao1",
        "west"    : __DIR__"jiedao4",
        "east"    : __DIR__"jiedao5",
        "up"    : __DIR__"jitai",
        "south"    : __DIR__"jiedao11",
      ]));
  set("objects", ([
        __DIR__"npc/people" : 1,
      ]));
  set("outdoors",__DIR__"");
  setup();
}

