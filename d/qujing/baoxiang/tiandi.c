// created by snowcat.c 10/14/1997
// room: /d/qujing/baoxiang/tiandi.c

inherit ROOM;

void create ()
{
  set ("short", "��ظ�");
  set ("long", @LONG

��ظ����Ʒ����������ƣ����ڻ��������˿�����������ʣ���
���ǽ�������ı����������Ĺ�����Ŀ�⾼����Ȼ������������
�н��¹�Ů���н������̣����а�ζ�����������

LONG);

  set("exits", ([
        "northdown"   : __DIR__"yujie6",
      ]));
  set("objects", ([
        __DIR__"npc/girl" : 2,
        __DIR__"npc/king" : 1,
       ]));

  setup();
}

