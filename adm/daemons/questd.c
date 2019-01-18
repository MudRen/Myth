// questd.c
// modify by mudring

//#pragma save_binary
#pragma optimize

#include <ansi.h>
#include <command.h>

string *quests;
string *roomlines;
mapping maps;

varargs void init_dynamic_quest(int hard);
varargs int spread_quest(string one_quest, int hard);
object find_env(object ob);
varargs int already_spreaded(string str, int hard);
int quest_reward( object me, object who,object quest_item);
int locate_quest(object me,string arg);
string dyn_quest_list();
string query_city(object loc);

void create()
{
   string file,dir,name;
   string* buf1;
   int i,size;
        
seteuid(getuid());
   maps=([]);
   file = read_file("/d/obj/quest/dynamic_location");
   roomlines = explode(file,"\n");
   file = read_file("/d/obj/quest/dynamic_quest");      
   quests = explode(file,"\n");
   file = read_file("/adm/daemons/find.map");
   buf1 = explode(file,"\n");
   size=sizeof(buf1);
   if(!size) return;

   for(i=0;i<size;i++) {
     if(sscanf(buf1[i],"%s %s",dir,name)==2) {
       name=replace_string(name," ","");
       if(strlen(dir)>2 && strlen(name)>2) {
         maps+=([dir:name]);
       }
     }
   }
/*
   CRON_D->set_last_hard_dis();
   init_dynamic_quest(1);
*/
}

// add some task reward, player will do it a lots
// add task log for player reward
// mudring Sep/07/2002
int quest_reward(object me, object who,object quest_item)
{
        int exp, pot, score, money;
        int times, count;
        string str, str1;

        if (who->query("name") != quest_item->query("owner_name"))
                return 0;
        if (userp(who)) return 0;

        times = me->query("task_job");
        if (times > 5000) return 0;
              count = times % 3; 
             if(count==2)
                  {
              if(me->query("task_job_time") && me->query("task_job_time") + 90 > time())
                    {
               who->command("say ������Ҳ̫���ˣ��ȵ�������!\n");
                 return 0;
                  }
                  me->set("task_job_time",time());
                   }
        count = times % 20;
        exp = 800 + 120 * (count + 1) + times / 5;
        if (exp > 2000) exp = 2000 + random(200);
        if (count == 19) exp += 1000;
        pot = exp / 10;

        if (random(2)) {
                me->add("daoxing", exp);
                me->add("potential", pot);
                tell_object(me, sprintf("������"HIR"%s"NOR"�ĵ��� ,"HIY"%s"NOR"��Ǳ�ܣ�\n"NOR,
                        chinese_daoxing(exp), chinese_number(pot)));
                str = " give " + filter_color(quest_item->name()) + " to " + filter_color(who->name()) + " got "
                      + exp + " daoxing " + pot + " pot.";
                str1 = "�ҵ���" + filter_color(quest_item->name()) + "����" + filter_color(who->name()) + "���õ���"
                      + chinese_daoxing(exp) + "�ĵ��к�" + pot + "��Ǳ��.";
        }
        else {
                me->add("combat_exp", exp);
                me->add("potential", pot);
                tell_object(me, sprintf("������"HIR"%s"NOR"����ѧ ,"HIY"%s"NOR"��Ǳ�ܣ�\n"NOR,
                        chinese_number(exp), chinese_number(pot)));
                str = " give " + filter_color(quest_item->name()) + " to " + filter_color(who->name()) + " got "
                      + exp + " exp " + pot + " pot.";
                str1 = "�ҵ���" + filter_color(quest_item->name()) + "����" + filter_color(who->name()) + "�õ���"
                      + exp + "����ѧ��" + pot + "��Ǳ��.";
        }
        score = me->query_temp("dynamic_find");        
        if (score + 1 == 10) {
                me->delete_temp("dynamic_find");
                money = 8000 + random(999);
                MONEY_D->pay_player(me, money);
                tell_object(me, "�����У�����Ѱ�ұ���Ĺ����еõ���"
                + MONEY_D->money_str(money) + "������֮�ƣ�\n");
                MONITOR_D->report_quest_object_msg(me, "find task 10 got " + money + " money");
                MONITOR_D->mudring_log("task", me, "find task 10 got " + money + " money");
        }
        else me->set_temp("dynamic_find", score + 1);
        MONITOR_D->report_quest_object_msg(me, str);
//115          MONITOR_D->report_rumor_object_msg(me, str1);
        MONITOR_D->mudring_log("task", me, str);
        me->add("task_job", 1);
        
        return 1;
}

varargs void init_dynamic_quest(int hard)
{
        int i;
        for( i=0; i < sizeof(quests)/2; i++)
                spread_quest(quests[i*2],hard);
}

varargs int spread_quest(string quest, int hard)
{
        object obj0,obj1,obj2,obj3;
        object cur_obj;
        object next_obj;
        object tar;
        object *inv;
        object *target=({});
        int i;
        string location;
        if(already_spreaded(quest,hard)) return 0;
        reset_eval_cost();
        location = roomlines[random(sizeof(roomlines))];
        obj0=find_object(location);
        if(obj0)
        obj0->reset();
        else
        obj0=load_object(location);
        cur_obj =obj0;
        if(cur_obj)
        {
        inv = all_inventory(cur_obj);
        for(i=0; i<sizeof(inv); i++) {
        if(inv[i]->is_character() && !userp(inv[i]))
        target += ({ inv[i] });
        if(inv[i]->is_container()) target += ({ inv[i] });
                }
        }
        if(sizeof(target)) cur_obj = target[random(sizeof(target))];
        if(cur_obj)
        {
        tar = new(quest);
        tar->set("value",0);
        tar->move(cur_obj);             
        }
return 1;
}


// modify list task ...mudring
string dyn_quest_list()
{
        string output;
        object item;
        int i;
        
   output="";
        for( i=0; i < sizeof(quests)/2; i++)
        {
        if(!objectp(item= find_object(quests[i*2])))
            item = load_object(quests[i*2]);
        if(already_spreaded(quests[i*2])) {
            if(random(2))
                        output += sprintf(WHT"��"YEL"   ��"NOR"����%s��%s��%s��    \n"NOR,item->query("owner_name"),item->query("name"),item->query("id"));
            else
                        output = sprintf(WHT"��"YEL"   ��"NOR"����%s��%s��%s��    \n"NOR,item->query("owner_name"),item->query("name"),item->query("id")) + output;

        } else
        {
            if(random(2))
                        output += sprintf(WHT"��"HIR"   �"NOR"��%s��%s��%s��    \n"NOR,item->query("owner_name"),item->query("name"),item->query("id"));
            else
                        output = sprintf(WHT"��"HIR"   �"NOR"��%s��%s��%s��    \n"NOR,item->query("owner_name"),item->query("name"),item->query("id")) + output;
        }
        }
        return output;
}
varargs int already_spreaded(string str,int hard)
{
        object ob,*ob_list;
        int i;
        if(!str) return 0;
        if(hard)
        {
        ob_list = children(str);
        for(i=0; i<sizeof(ob_list); i++) {
                ob=find_env(ob_list[i]);
                if(ob)
                { ob_list[i]->move(VOID_OB);
                 destruct(ob_list[i]);
                }
        }
        return 0;
        }
        else
        {
        if(!str) return 0;
        ob_list = children(str);
        for(i=0; i<sizeof(ob_list); i++) {
                ob=find_env(ob_list[i]);
                if(ob)
                        return 1;
        }
        return 0;
        }
}

object find_env(object ob)
{
        while(ob)
        {
        if(ob->query("exits") ) return ob;
        else ob=environment(ob);
        }
        return ob;
}

int locate_quest(object me, string arg)
{
    object loc;
    string qloc,msg,quest;
    string* exlst;
    object* itemlist;
    mapping exits;
    int index,i;
    
if( ! arg)
return notify_fail("locate <��Ʒid>\n");
    if(present(arg,me))
        return notify_fail("�����������������\n");

    if((index=member_array(arg,quests,0))>0)quest=quests[index-1];
    else return 1;
    
    if(!already_spreaded(quest)){
        tell_object(me,HIW"�ر�ͼ"NOR"һ�㷴ӦҲû�У��·���������������������ϡ�\n");
        return 0;
    }

    itemlist = children(quest);
    for(index=0;index<sizeof(itemlist);index++){
      if(objectp(loc=find_env(itemlist[index]))){
          qloc = query_city(loc);
          exits=loc->query("exits");
          exlst=keys(exits);
          msg=HIW+itemlist[index]->query("name")+NOR"�·���"HIG+qloc+
              NOR"һ����";
          if(sizeof(exlst)){
                for(i=0;i<sizeof(exlst)-1;i++)msg+=exlst[i]+"��";
                msg+=exlst[sizeof(exlst)-1]+"���ڵĵط���\n";
                tell_object(me,HIW"�ر�ͼ"NOR"��ʾ��\n"+msg);
                return 1;
          }    
      }
    }   
    tell_object(me,HIW"�ر�ͼ"NOR"һ�㷴ӦҲû�С�\n");
    return 1;
}

string query_city(object loc)
{
        string filename,filename1;
        int len;
        
        filename=file_name(loc);
        len=strlen(filename);
        if(len<2) return "???";

        len--;
        while(filename[len]!='/' && len>0) {
          len--;
        }
        if(len<2) return "???";

        filename1=filename[1..(len-1)];
        return maps[filename1]; 
}

/*
// why not used combatd??
// this function changed to use combatd
// mudring Sep/07/2002
string daoxing(int dx)
{
        
        int day,hour;
        day = (dx) / 4;
        hour = (dx  - day * 4) * 3; 
        return day?(chinese_number(day)+"��"):""+hour?(chinese_number(hour)+"ʱ��"):"";
}
*/

