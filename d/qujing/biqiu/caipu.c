// created by snowcat 11/21/1997

inherit ROOM;

void create ()
{
  set ("short", "����");
  set ("long", @LONG

��������Ÿ��໨���辰�������ڻ����ϣ�����������ֽ��ī
֮��������������ֹ������Ļ�����ƿ����������������
�������Ϊ��Ʒ��

LONG);

  set("exits", ([
        "north"    : __DIR__"jie3",
      ]));
  set("objects", ([
        __DIR__"npc/binumuyi"    : 1,
      ]));
  setup();
}

