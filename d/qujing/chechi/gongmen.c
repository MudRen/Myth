// created by snowcat.c 10/21/1997
// room: /d/qujing/chechi/gongmen.c

inherit ROOM;

void create ()
{
  set ("short", "����");
  set ("long", @LONG

���ٹ������Ͽ����ű����г�𶤣�����Ƕ�Ű����ܡ�ׯ�����¡�
�Ŷ���ɹ��ʼ���˫�У���¥�ϵ��������������ȸ��������
�ϼ�������

LONG);

  set("exits", ([
        "west"         : __DIR__"gong5b",
        "east"         : __DIR__"gong5d",
        "south"        : __DIR__"zhong",
        "north"        : __DIR__"zhaomen",
      ]));

  set("outdoors","/d/qujing/chechi");
  setup();
}

int valid_leave (object who, string dir)
{
  if ((! interactive(who)) &&
      dir == "south")
    return 0;
  return ::valid_leave(who,dir);
}
