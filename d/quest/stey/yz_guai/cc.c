//By tianlin@Mhxy for 2001.12.30

#include <ansi.h>

inherit F_DBASE;
 
string *glist=({"yg-jjf","yg-jjf2","yg-jjf3","yg-hyd", 
                "yg-fangcun","yg-hell","yg-jjf4","yg-dragon1", 
                "yg-dragon2","yg-moon","yg-dragon3","yg-pansi", 
                "yg-putuo","yg-shushan","yg-wdd", 
        }); 


void create() 
{ 
        seteuid(getuid()); 
        set("channel_id",""); 
// 
       call_out("start",5); 
} 
void start() 
{ 
 //       this_object()->apply_condition("ximo_choose",360); 
     this_object()->choose_npc(); 
} 

void choose_npc()
{
        int i, j ,k,ppl;
        object *list,*glidt, newob,env;
        string str;
        list = users();
        i = sizeof(list);

        if (i < 10){
        remove_call_out("choose_npc");
        call_out("choose_npc",60);
        return;
                   }

       
        while( i-- ) {
                 env=environment(list[i]);
                 if(!wizardp(list[i]) && env && !(env->query("no_fight") || 
                 !env->query("no_magic"))) {  
                        if ( (list[i]->query("combat_exp") + list[i]->query("daoxing"))> 180000000 )
                      {
                newob = new("/d/quest/stey/yz_guai/"+glist[random(sizeof(glist))]); 
                newob->set("target",list[i]);
                newob->invocation(list[i], 4+random(4));
                if(newob->move(env)){
                         newob->command("follow "+list[i]->query("id"));
                         newob->command("kill "+list[i]->query("id"));
                         ppl++;
                                    }
                else
                destruct(newob);
                       }
                                          }
                      }
     

        reset_eval_cost();
        if (ppl)
        {
        
        message("channel:job",NOR+HIM"��"NOR+HIW"������"NOR+HIM"��"NOR+CYN+"Ӱ��ħͷ��"NOR+HIC+chinese_number(ppl)+NOR+CYN"�����������ɱ����������\n"NOR,users());
        
        remove_call_out("choose_npc");
        call_out("choose_npc",1200);
        }
        else
        {
        message("channel:job",NOR+HIM"��"NOR+HIW"������"NOR+HIM"��"NOR+CYN"��ƽ�˾�������ల���¡�����\n"NOR,users());
        remove_call_out("choose_npc");
        call_out("choose_npc",120);
        }
}


