// created by snowcat 4/4/1997
// room: /d/nuerguo/shanpo.c

inherit ROOM;

void create ()
{
  string dir;
  set ("short", "ɽ·");
  set ("long", @LONG

Ұ���̹⵭��ɳ����ɫ�֡�һ·������ɫ�������������о�
����ĸ���ˡ����˺Ӿ�������Ů���ؽ硣

LONG);

/*
  dir = __DIR__;
  dir[strlen(dir)-8] = 0;
*/
  dir = "/d/";
  set("exits", ([
         "southeast" : dir+"qujing/jindou/shanlu6",
         "west" : __DIR__"eastriver1",
      ]));
  set("outdoors", __DIR__"");

  //set("objects",([
  //      __DIR__"obj/story" : 1,
  //     ]));

  setup();
}






