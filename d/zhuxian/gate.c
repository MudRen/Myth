inherit ROOM;

void create ()
{
  set ("short", "�յ�");   
  set ("long", @LONG   
�������ʮ��������ǰһ������Ȼ��һ��յأ�����վ�������ˡ�
LONG);

    set("exits", ([ 
               "south" : __DIR__"hongsha",
                 ]));
    set("objects",([
                    __DIR__"npc/ttjz" : 1,
                    __DIR__"npc/ystz" : 1,
                    __DIR__"npc/xyhd" : 1,
                 ]));
  set("outdoors", __DIR__);
    setup();
}
