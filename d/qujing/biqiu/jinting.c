// created by snowcat 11/21/1997

inherit ROOM;

void create ()
{
  set ("short", "��ͤ��");
  set ("long", @LONG

��ͤ��ΪԶ�������Ŀ��˶��裬����һ�����ƺ������������
��ľ�����ͼ������ӣ�ǽ�������ϯɴ��ľ�����м�λ������
�ڹ�����Ϣ���졣

LONG);

  set("exits", ([
        "west"    : __DIR__"jie3",
      ]));
  set("objects", ([
        __DIR__"npc/suohana"    : 1,
      ]));
  set("sleep_room",1);
  set("if_bed",1);
  set("valid_startroom", 1);
  setup();
}

