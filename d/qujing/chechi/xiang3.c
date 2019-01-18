// created by snowcat.c 10/21/1997
// room: /d/qujing/chechi/xiang3.c

inherit ROOM;

void create ()
{
  set ("short", "�᷿");
  set ("long", @LONG

�᷿���������룬�ϱ�����һ��ש�󿻣����Ž����ޱ�������
��Ӳľ���������в�����롣ǽ����һЩ�ֻ���д�ţ�������
��������ҹ��������

LONG);

  set("exits", ([
        "west"         : __DIR__"xiang2",
      ]));

  set("objects", ([
         __DIR__"npc/daoshi"    : 2,
      ]));
  set("sleep_room",1);
  set("if_bed",1);
  setup();
}

void init ()
{
  object shi1 = present ("dao shi 1", this_object());
  object shi2 = present ("dao shi 2", this_object());

  remove_call_out ("sleeping");
  if (random(2))
    call_out ("sleeping",1+random(3),shi1);
  else
    call_out ("sleeping",1+random(3),shi2);
}

void sleeping (object shi)
{
  if (! shi)
    return;
  if (interactive(shi))
    return;
  shi->command_function("sleep");
}
