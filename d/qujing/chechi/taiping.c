// created by snowcat.c 10/21/1997
// room: /d/qujing/chechi/taiping.c

inherit ROOM;

void create ()
{
  set ("short", "̫ƽ��");
  set ("long", @LONG

̫ƽ������ש�̳ɣ����Ӳ�̫�󡣳������ƾɵ�������̳������
ϡϡ�����س���һЩ�ݲݡ��������ǳ��ٹ��ıȽ����ֵĵضΣ�
�������ص������ڳ����߹���

LONG);

  set("exits", ([
        "west"         : __DIR__"ximen",
        "north"        : __DIR__"caichang",
        "south"        : __DIR__"jieshi6",
      ]));

  set("outdoors","/d/qujing/chechi");
  setup();
}

