inherit ROOM; 
#include <ansi.h> 
// 
#include "valid_leave.h" 
void create () 
{ 
        set ("short",HIG "����"NOR); 
        set ("long",HIG @LONG 
 
 
                        ���ϸ��¥            
 
 
          ���ϸ�꣬��Ӱ������ ѩ����΢͸�� �ٷ�����  
 
 
LONG NOR); 
 
 
        set("exits",  
        ([ //sizeof() == 4 
                "north" : "/d/kaifeng/wuguan/home3", 
                "south" : "/d/kaifeng/wuguan/home1", 
        ])); 
 
        set("objects",  
        ([ //sizeof() == 1 
        __DIR__"npc/qfxytang1" : 1,
           ])); 
 
     set("can_leave","south"); 
     set("clubb","���ϸ��¥"); 
 
        set("no_clean_up", 0); 
        setup(); 

} 


