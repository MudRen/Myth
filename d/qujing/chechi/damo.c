// created by snowcat.c 10/21/1997
// room: /d/qujing/chechi/damo.c

inherit ROOM;

void create ()
{
  set ("short", "��Ħ��");
  set ("long", @LONG

��Ħ����տ���Ҳ�����Ź������ҵض����ݽǡ�ǽ����ѣ��Ŵ�
�޴档���Ϻ��ҵ����Ÿɲݣ��������һЩ�ƾ����š���������
��һͨ����

LONG);

  set("exits", ([
        "northwest"     : __DIR__"jingang",
      ]));

  set("objects", ([
        __DIR__"npc/heshang"    : 3,
      ]));
  setup();
}

