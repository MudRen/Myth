// created by snowcat.c 10/21/1997
// room: /d/qujing/chechi/zhong.c

inherit ROOM;

void create ()
{
  set ("short", "�г�");
  set ("long", @LONG

�г��ڻʹ������棬�ô��ʯͷ�̳ɣ����ǻʹ�����ڣ�Ʈ��
���ٹ�����졣ÿ������ʱ�֣���ʿ��������������������Ƕ�
����������������

LONG);

  set("exits", ([
        "west"         : __DIR__"xi",
        "north"        : __DIR__"gongmen",
        "east"         : __DIR__"dong",
      ]));

  set("outdoors","/d/qujing/chechi");
  setup();
}

int valid_leave (object who, string dir)
{
  if ((! interactive(who)) &&
       dir == "north" &&
       who->query("people")=="people")
    return 0;
  return 1;
}
