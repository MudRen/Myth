// created by snowcat 12/2/1997

inherit ROOM;

void create ()
{
  set ("short", "�ӻ���");
  set ("long", @LONG

���治��С�����ϰ�������ɢɢ������Ʒ���͵͵��컨����
����һЩ�ҹ���������������Ҳ����һЩ�����۵Ļ������
�����Ŵ󿪣�ͨ�����¥�Ĺ㳡��

LONG);

  set("exits", ([
        "south"    : __DIR__"wugu",
      ]));
  set("objects", ([
"/obj/boss/qinfa_qian"    : 1,
      ]));
  setup();
}

