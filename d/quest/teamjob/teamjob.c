

#include <ansi.h>

mixed names = ({
        ({
        "��ȸ����","��������","�׻�����","��������","�찲��",
        "�������","�����ھ�","�����","������","Ȫ������",
        "��������","�������","����¥","������","��ɽ����",                
        "�߹���","�����ַ�","��������","ϲ�ݳ�","��³��", 
        "����","ɽ����","����ͷ","�������","��ɽ����",
        "����Ժ","ӿȪ��","������","���Ϸ�","�Ͻ��",
        "�ɷ��","����ɽ��","������","����̶","���ɷ�",                
        "��Ӧ��","�����","������Ժ","������","������", 
        }),
        ({
                 "�α�","��å","ƫ��","�Խ�","����","С��","�к�","��ܽ","������",
                 "С��","����ϰ�","����ͨ","�","����","������","��С��","�α�",
                 "����ʦ̫","����ʦ̫","��Զ��","Ī����","½�˷�","������","��ҩʦ","��׺�",
                 "��Ұ��","�˰ٴ�","��־ƽ","С��Ů","���з�","ŷ����","������Ů","�������",
                 "����","������","������","������","����Ⱥ","�����","�����ʦ","���Ʊ���",
                 "��������","ׯ����","˫��","������","ľ����","��Զɽ","������","������",
                 "����","�ڰ���","������","������","�彣��","��ص���","����","����",
                 "��ɽͯ��","ΤһЦ","лѷ","�μ�","½�˷�","�Ŵ�ɽ","������","�������",
                 "ʯ����","���Ǻ�","Ľ�ݸ�","�쵤��","����","�ⲻƽ",
                 "������","ʷ��ɽ","������","����ɩ","֣��ͷ","��һ��",
                 "½��Ӣ","������","��ݼ","����","Ԭ����","������",
                 "������","������","��ص���","��Ӣ","�ʱ���","���з�",
                 "ˮ�","׿��","���׷�","�ɲ���","�����","��Ա��",
                 "������","������","��������","�����ϼ�˾","�����","������",
                 "������","Ǯ�ཡ","�Ϻ�����","��׺�","�ŵ���","������",
                 "�����ɺ���","�����ɹ���","�ɻ���","����","��ϲ��","������",
                 "������","����������","��ũ�����","����","������","��˹����",
                 "����ľ��","������Ů","����Ů","��","���Ʋֹ�ʦ","����",
        }),
        });

string ask_jianxi()
{     
        object guo,ob;
        object *team;
        int i=0,count=0,minexp,maxexp;
        string where;
        guo =this_object();
        ob=this_player();
          
        if (guo->query_condition("zzz_busy"))
                return "Ŀǰ��δռ������ħ����ħ˽��͵���ɹ����";//guo busy time 
          
        if(ob->query("combat_exp")<500000)
                return  "����Ŀǰ����Ϊ�в��ܵ��˴��Ρ�";//too low exp
        team=ob->query_team();
        count=sizeof(team);
       //write("\n"+sprintf("%d",count));
        if(count<=1)
                return "����һ���˿����Ƶ�������"; //too few people
        if(count>=6)
                return "���²��������������Ϊ�"; //too many people
        minexp=team[0]->query("combat_exp");
        maxexp=minexp;
      
        for(i=1;i<count;i++)
        { if(team[i]!=0)
          { if(team[i]->query("combat_exp")<minexp)
                minexp=team[i]->query("combat_exp");
            if(team[i]->query("combat_exp")>maxexp)
                maxexp=team[i]->query("combat_exp");
          }
        }
        if ((maxexp-minexp)>1000000)
                return "���ǵ��书���̫�����⡣";//exp too far
     //check ok
      
          where=names[0][random(40)];
          guo->apply_condition("zzz_busy",30);
          ob->set_temp("team_count",count);
          ob->apply_condition("zzz_busy",60);
          for(i=0;i<count;i++)
          //team[i]->set_temp("zzz_job_zhuji",1);
          team[i]->apply_condition("zzz_busy",60);
          for(i=100;i*i*i/10<=maxexp;i++);
          call_out("job",60,ob,where,i,count+2);
          //message_vision(HIY"$N��Ц���ѣ���ƾ���Ǽ���Ҳ�뵲ס�ҵ�ȥ·?\n"NOR, obj);
          return    "���粻�ң���˵ħ��һ����͵�����칬�ķ�����\n"+
                        "         ��������ȥ"+where+"�����أ����ط�������(chuansong)���칬��\n"+
                            "          ��·��ħ��ֿ϶���ȥ��Ӧ�������Ƕ��С�ġ�"; 
}


void job(object ob,string where,int maxpot,int ckiller)
{    
        object *team,obj,gift;
        object guo=this_object();
        int i=0;
        //team=ob->query_team();
        //for(i=0;i<sizeof(team);i++)
        if(environment(ob)->query("short")!=where && ob->query_condition("zzz_busy"))
        {
             tell_object(ob, HIY "\n�����صĵط����԰ɣ������Ѿ������ˣ�������ʧ���ˣ�\n" NOR); 
        }
        guo->apply_condition("zzz_busy",0);

        if(environment(ob)->query("short")==where&&ob->query_condition("zzz_busy"))
        { if (ckiller>0)
             { if (random(20)>16)
                  { obj=new(__DIR__"yaomoguiguai");   
                    obj->do_copy(ob,maxpot,3);
                    obj->set("nickname",HIY"���µ�һħ"NOR);     
                    obj->move(environment(ob));
                    obj->kill_ob(ob);
                   }
                else 
                   { obj=new(__DIR__"yaomoguiguai"); 
                     obj->do_copy(ob,maxpot,1);
                     
                     obj->move(environment(ob));
                     obj->kill_ob(ob);
                     obj=new(__DIR__"yaomoguiguai");
                     if (random(20)>10)
                        { obj->do_copy(ob,maxpot,2);
                          obj->set("nickname",HIY"ħ�����»���"NOR);
                         }
                     else 
                         obj->do_copy(ob,maxpot,1);
                         obj->move(environment(ob));
                         obj->kill_ob(ob);
                    }  
                 call_out("job",120,ob,where,maxpot,ckiller-1);
              }
          else 
              { if (present("yaomo guiguai",environment(ob)))
                   {//present menggu dahan,then mission failed
                      tell_room(environment(ob),HIC"ħ�������ħ��ֻӻ��֣�ʾ���������ߡ�\nħ�������Ҵ�ææ���뿪�ˡ�\n"NOR);
                      tell_object(ob, HIY "\n���������ˣ�������ʧ�ܣ�\n" NOR); 
                    }
                else{
                                obj=new(__DIR__"thief"); 
                                obj->do_copy(ob,maxpot);
                                obj->set("nickname",HIR"���ֿտ�"NOR);
                                obj->move(environment(ob));
                                message_vision(HIY"$N��Ц���ѣ���ƾ���Ǽ���Ҳ�뵲ס�ҵ�ȥ·��\n"NOR, obj);
                                obj->kill_ob(ob);
                                gift=new(__DIR__"fabao");
                                gift->set_temp("host",ob->query("id"));
                                gift->move(obj);
                     }
              }
         }
      else
              tell_object(ob, HIY "\n����͵͵������칬��������ʧ�ܣ�\n" NOR); 
          
              return;

}                       
       
           
       
     





