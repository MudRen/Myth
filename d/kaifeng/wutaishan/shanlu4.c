
inherit ROOM;

void create ()
{
   set ("short", "ɽ·");
   set ("long", @LONG
        
�����ɴ���ɽ�͵��������ˣ�ǰ��һ��ʯ�����Ǵ�˵������
��������������������ʯ(stone)��
LONG);

   set("item_desc", (["stone" : "��ʯʯ�����ף�����װ룬 ������Χʮ���ף�ʯ����ɫ����
���ƣ��������ϣ��������⡣\n", ]));
   //for look something.
   

   set("exits", 
   ([ //sizeof() == 4
      "southdown" : __DIR__"shanlu2",
     "north" : __DIR__"door",
     
   ]));
   
   set("objects", 
   ([ //sizeof() == 1
     //__DIR__"npc/***" : 1,
   ]));


   set("outdoors", "/d/nanhai");

   setup();
}

