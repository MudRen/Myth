// created by snowcat 12/2/1997

inherit ROOM;

void create ()
{
  set ("short", "��Ӫ");
  set ("long", @LONG

ľ�Ƶľ�Ӫ��䱸ɭ�ϣ���������һ��ʿ������һ�������
����վ����Ŀ��б�ӡ�Ӫ����Լ������ս��˻������ʱ��ͭ��
��������

LONG);

  set("exits", ([
        "south"    : __DIR__"gongmen",
      ]));
  set("objects", ([
         __DIR__"npc/junshi"    : 6,
      ]));
  setup();
}

