// created by snowcat.c 10/14/1997
// room: /d/qujing/baoxiang/mazhan.c

inherit ROOM;

void create ()
{
  set ("short", "��ջ");
  set ("long", @LONG

�����Ǹ����׵Ŀ�ջ������һ��ľ��б���Σ�������һ�ų����Ĵ�
齡�������Զ���������Խ������н���ջ���ϰ壬Ȼ�������Ϣһ
����

LONG);

  set("exits", ([
        "west"       : __DIR__"bei4",
      ]));

  set("sleep_room",1);
  set("if_bed",1);
  set("valid_startroom", 1);
  setup();
}

