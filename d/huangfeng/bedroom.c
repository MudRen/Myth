// created by angell 1/1/2001
// room: /d/qujing/huangfeng/bedroom.c

inherit ROOM;

void create ()
{
  set ("short", "��Ϣ��");
  set ("long", @LONG

��Ϣ�Ҳ��õü򵥸ɾ����ϱ߿�����һ�̺�ש�󿻣����Ų���
ɫ���ޱ������ϰ��˸�����������һ����¯���������̴�¯��
���������������䡣

LONG);

  set("exits", ([
        "east"         : __DIR__"chanyuan",
      ]));

  set("objects", ([
      ]));
  set("sleep_room",1);
  set("if_bed",1);
  setup();
}

