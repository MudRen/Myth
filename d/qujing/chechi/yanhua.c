// created by snowcat.c 10/21/1997
// room: /d/qujing/chechi/yanhua.c

inherit ROOM;

void create ()
{
  set ("short", "�̻�Ժ");
  set ("long", @LONG

�̻�Ժ����Щ��ͷ�ˣ�Ժ����ɴ�ʺ�ɫ�����������˱ǣ�����
����������Ŀ�����Ϸ���˿������ӹرյ������ź���������
Ů��Ц����������

LONG);

  set("exits", ([
        "north"         : __DIR__"jieshi8",
      ]));
  set("objects", ([
        __DIR__"npc/jinchai"   : 1,
      ]));

  setup();
}

