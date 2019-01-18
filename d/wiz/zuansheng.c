
inherit ROOM;

void create()
{
        set("short", "轮回转生界");
        set("long", @LONG
往事如烟，皆为飘渺，来了这里，你感觉一切皆虚无。
LONG
        );
        
        set("valid_startroom", 1);
  set("objects", ([ /* sizeof() == 1 */ 
  "/adm/npc/lunhuinpc" : 1, 
 
])); 
 

        setup();
        
}

void init()
{   
        if (!wizardp(this_player())) {
          this_player()->set("startroom","/d/wiz/zuansheng");
          this_player()->add("come_here",1);
          if(this_player()->query("come_here")> 12)
             { this_player()->command("ask lunhui pusa about 投胎");
              this_player()->delete("come_here");
              this_player()->command("agree"); }
          this_player()->save();
          add_action("block_cmd","",1);         
        }
        
}

int block_cmd()
{
        string verb = query_verb();
        
        if (verb=="say") return 0; //allow say
        if (verb=="help") return 0;
        if (verb=="look") return 0;
        if (verb=="ask") return 0;
        if (verb=="yes") return 0;
        if (verb=="no") return 0;
        return 1;
}

