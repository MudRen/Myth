//Cracked by Roath
// create by snowcat.c 12/8/1997

inherit ROOM;

void create ()
{
  set ("short", "��ľ��");
  set ("long", @LONG

������ľ��ҡҡ�ڰڣ�ľͷ�ϳ����˻���̦����

LONG);

  set("exits", ([
        "south"   : __DIR__"lingyun2",
        "northwest"   : __DIR__"lingyun1",
      ]));
  set("outdoors", __DIR__);

  setup();
}

void init ()
{
  call_out ("shaking",random(3)+1);
}

void shaking ()
{
  tell_room (this_object(),"��ľ������бб�ػε���һ�¡�\n");
}
