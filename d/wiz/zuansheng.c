
inherit ROOM;

void create()
{
        set("short", "�ֻ�ת����");
        set("long", @LONG
�������̣���ΪƮ�죬���������о�һ�н����ޡ�
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
             { this_player()->command("ask lunhui pusa about Ͷ̥");
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

