// Room: /d/jjf/se_garden.c

inherit ROOM;

void create()
{
	set("short", "��԰");
	set("long", @LONG
һ��С��԰����Ȼ�Ȳ��ϸ�����Ժ�������ǧ�죬��Ҳ���õ�
���¿��ˡ��ظ�����Ȼ��������֮ʿ���������һ�ʢ�������ճ���
��ɻ����������ջ����ޣ���������һƬ��ѩ����
LONG
	);
	set("exits", ([ /* sizeof() == 4 */
  "southeast" : __DIR__"son_cabinet",
  "north" : __DIR__"ne_garden",
  "west" : __DIR__"sw_garden",
  "northwest" : __DIR__"nw_garden",
]));
	set("no_clean_up", 0);
//        set("no_fight", 1); 
        set("no_magic", 1); 

	setup();
	replace_program(ROOM);
}
/*
      void init() 
      { 
          add_action("do_perform", "perform"); 
      } 
      int do_perform(string arg) 
      { 
              object who = this_player(); 
             object me = this_object(); 
                      tell_object(who, "��������԰�����徲֮�أ�����Ū��Ū������\n"); 
                return 1; 
      } 
*/
