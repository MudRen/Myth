//crack by stey

inherit ROOM;

void check_zuochan(object me);
void finish(object me);
void reward(object me);
string chinese_time(int timep);

string *str=({
                "����������������\n",
                "�����һ��ʤ�����趼�ǹ������̡�\n",
                "������Լ�������һ��ǰ��δ�еľ��硣\n",
                "����ľ�����������\n"
                "�����������򵽷�ľ��衣\n",
                "���˼����������������\n"
             });

void create ()
{
  set ("short", "����");
  set ("long", @LONG
����յ����ģ�ֻ�ڿ���ǽ�ڵĵط���������ط���һЩ���š�
������ߺܰ���ǽ�ڲ�֪����ʲô�������ģ��ᷢ�������Ļ�
�⡣����������(zuochan)����ĺõط�����Ҫ��ʵ�ڶ�������
Ҳ���Գ�ȥ�����ٻ���(halt)��

LONG);

  set("exits", ([
          "north"   : __DIR__"baoge1",
      ]));
  
  set("no_fight", 1);
  set("no_time",1);
  set("no_magic", 1);
  setup();
}

void init()
{
    add_action("do_zuochan", "zuochan");
    add_action("do_halt", "halt");
}

int do_zuochan()
{       int zuochan_time;

        object me = this_player();
        
        if (me->query("rulaitask/get"))
             {tell_object(me,"��������������������������\n"); 
              return 1;
             }

        if (me->query_temp("zuochan"))
             {tell_object(me,"��������������\n");
              return 1;
             }

        message_vision("$N��ϥ����һ�������ϣ�Ǳ˼�붨����ʼ�����Լ���������Ϊ��\n",me);
        me->set_temp("no_move", 1);
        me->set_temp("zuochan", 1);
        if ( !me->query("rulaitask") )  finish(me);
        else {
                if (me->query("rulaitask/fail"))
                zuochan_time = 30+random(16);
                else zuochan_time = 10+random(16);
                me->set_temp("zuochan_time",zuochan_time);

                check_zuochan(me);
              }
                     
        return 1;
}


void check_zuochan(object me)
{       
        int zuochan_time = me->query_temp("zuochan_time");

          if (!me->query_temp("zuochan")) return; 
        if ( zuochan_time <= 0 ) finish(me);
        
        else {
                if ( zuochan_time%6 == 0 )
                      tell_object(me,str[random(sizeof(str))]);
                me->add_temp("zuochan_time", -1);
                me->add_busy(1);
                call_out("check_zuochan",1,me);
              }
}


void finish(object me)
{
        tell_object(me,"��ֻ����̨һƬ�������ƺ������Ѿ���\n");
        message_vision("$N��������˿�����վ��������\n",me);
        me->delete_temp("no_move");
        me->delete_temp("zuochan");
        if (me->query("rulaitask/accomplish")) reward(me);
        me->delete("rulaitask");
        me->set("rulaitaskjob/done",1);
        me->apply_condition("rulai_job",25+random(50));
}

void reward(object me)
{
        int wuxue,level,kind_bonus,level_bonus,timep,num;
        int extra_bonus,potential_bonus,combat_exp_bonus,daoxing_bonus;
        string str,kind,time,msg;
        string logpath = "rltask";
        
        wuxue = me->query("combat_exp");
        level = me->query("rulaitask/level");
        kind  = me->query("rulaitask/kind");     
        timep = me->query("rulaitask/end_time")-me->query("rulaitask/start_time");
        time  = CHINESE_D->chinese_time(timep);
/*        
        if ( level == 1 ) level_bonus=300;
        else if ( level == 2 ) level_bonus=800;
        else level_bonus=1200;
        
        if ( kind == "ɱ" ) kind_bonus=300;
        else if ( kind == "��" ) kind_bonus=500;
        else if ( kind == "Ȱ" ) kind_bonus=900;
        else kind_bonus=1200;
        
        //if ( me->query("combat_exp") < 20000000)                   
                        
        extra_bonus = (me->query("combat_exp")/2000)+kind_bonus;
                          
        //if( extra_bonus > 8000) extra_bonus =8000;
        if ( me->query("combat_exp") < 30000000)   
        {  
                potential_bonus = (random(extra_bonus) + level_bonus + kind_bonus)*2/6;
                daoxing_bonus = (extra_bonus*6 + (random(level_bonus) + random(kind_bonus))*2)/6;
                combat_exp_bonus = (extra_bonus*5 + (random(level_bonus) + random(kind_bonus))*3/2)/6;
        }
        else
        {
                potential_bonus = (random(extra_bonus) + level_bonus + kind_bonus)*2/9;
                combat_exp_bonus = (extra_bonus*5 + (random(level_bonus) + random(kind_bonus))*2)/7;                                            
                daoxing_bonus = (extra_bonus*5 + (random(level_bonus) + random(kind_bonus))*2)/7;
        }
        if ( (me->query("combat_exp") > 50000000 && me->query("combat_exp")) < 150000000 || !me->query_temp("rulai_task"))   
        {  
// ��ֹ����Խ��Խ��,�������
                if (combat_exp_bonus>20000) combat_exp_bonus=20000;
                if (daoxing_bonus>20000) daoxing_bonus=20000;
        }
        if(!me->query_temp("rulai_task"))
        {
                daoxing_bonus /=2;
                combat_exp_bonus /=2;
                potential_bonus /=2;
         }
// mudring moved num to quizd for a big bug.
         else {me->delete_temp("rulai_task");}

        me->add("potential", potential_bonus);
        me->add("combat_exp", combat_exp_bonus);
        me->add("daoxing", daoxing_bonus);
        str = "�õ���"+potential_bonus+"��Ǳ�ܣ�";
        str +=combat_exp_bonus+"��ѧ���飬";
        str += COMBAT_D->chinese_daoxing(daoxing_bonus)+"���С�";
        tell_object(me,"��õ���"+potential_bonus+"��Ǳ�ܣ�"+combat_exp_bonus+"��ѧ���飬"+COMBAT_D->chinese_daoxing(daoxing_bonus)+"���С�\n");
        if(me->query("quiz_combat_exp"))
        {
                me->add("combat_exp",me->query("quiz_combat_exp"));
                me->add("daoxing",me->query("quiz_daoxing"));
                me->add("balance",me->query("quiz_balance"));
                me->add("potential",me->query("quiz_potential"));
                me->delete("quiz_balance");
                me->delete("quiz_combat_exp");
                me->delete("quiz_daoxing");
                me->delete("quiz_potential");
                me->save();
                tell_object(me,"��õ��˶�������⽱����\n");
        }
*/
//wuyou�޸�������
        
        if ( level == 1 ) level_bonus=300;
        else if ( level == 2 ) level_bonus=600;
        else level_bonus=900;
        
        if ( kind == "ɱ" ) kind_bonus=200;
        else if ( kind == "��" ) kind_bonus=300;
        else if ( kind == "Ȱ" ) kind_bonus=600;
        else kind_bonus=800;
                                                  
        extra_bonus = (me->query("combat_exp")/2000)+kind_bonus;
                          
        if ( me->query("combat_exp") < 30000000)   
        {  
                potential_bonus = (random(extra_bonus) + level_bonus + kind_bonus)*2/6;
                daoxing_bonus = (extra_bonus*6 + (random(level_bonus) + random(kind_bonus))*2)/6;
                combat_exp_bonus = (extra_bonus*5 + (random(level_bonus) + random(kind_bonus))*3/2)/6;
        }
        else
        {
                potential_bonus = (random(extra_bonus) + level_bonus + kind_bonus)*2/10;
                combat_exp_bonus = (extra_bonus*5 + (random(level_bonus) + random(kind_bonus))*2)/8;                                            
                daoxing_bonus = (extra_bonus*5 + (random(level_bonus) + random(kind_bonus))*2)/8;
        }

        if ( (me->query("combat_exp") > 50000000 && me->query("combat_exp")) < 200000000 || !me->query_temp("rulai_task"))   
        {  
// ��ֹ����Խ��Խ��,�������
                if (combat_exp_bonus>20000) combat_exp_bonus=15000;
                if (daoxing_bonus>20000) daoxing_bonus=15000;
        }

        num = random(5);
        switch (num) {
        case 0:
                combat_exp_bonus = 0;
                me->add("potential", potential_bonus);
                //me->add("combat_exp", combat_exp_bonus);
                me->add("daoxing", daoxing_bonus);
                str = "�õ���"+potential_bonus+"��Ǳ�ܣ�";
                //str +=combat_exp_bonus+"��ѧ���飬";
                str += COMBAT_D->chinese_daoxing(daoxing_bonus)+"���С�";
                tell_object(me,"��õ���"+potential_bonus+"��Ǳ�ܣ�"+COMBAT_D->chinese_daoxing(daoxing_bonus)+"���С�\n");
                break;
        case 1:
                daoxing_bonus = 0;
                me->add("potential", potential_bonus);
                me->add("combat_exp", combat_exp_bonus);
                //me->add("daoxing", daoxing_bonus);
                str = "�õ���"+potential_bonus+"��Ǳ�ܣ�";
                str +=combat_exp_bonus+"��ѧ���飬";
                //str += COMBAT_D->chinese_daoxing(daoxing_bonus)+"���С�";
                tell_object(me,"��õ���"+potential_bonus+"��Ǳ�ܣ�"+combat_exp_bonus+"��ѧ���顣\n");         
                break;
        case 2:
                daoxing_bonus = daoxing_bonus*2/3;
                combat_exp_bonus /=2;
                potential_bonus /=2;        
                me->add("potential", potential_bonus);
                me->add("combat_exp", combat_exp_bonus);
                me->add("daoxing", daoxing_bonus);
                str = "�õ���"+potential_bonus+"��Ǳ�ܣ�";
                str +=combat_exp_bonus+"��ѧ���飬";
                str += COMBAT_D->chinese_daoxing(daoxing_bonus)+"���С�";
                tell_object(me,"��õ���"+potential_bonus+"��Ǳ�ܣ�"+combat_exp_bonus+"��ѧ���飬"+COMBAT_D->chinese_daoxing(daoxing_bonus)+"���С�\n");
                break;
        case 3:
                combat_exp_bonus = combat_exp_bonus*2/3;
                daoxing_bonus /=2;
                potential_bonus /=2;        
                me->add("potential", potential_bonus);
                me->add("combat_exp", combat_exp_bonus);
                me->add("daoxing", daoxing_bonus);
                str = "�õ���"+potential_bonus+"��Ǳ�ܣ�";
                str +=combat_exp_bonus+"��ѧ���飬";
                str += COMBAT_D->chinese_daoxing(daoxing_bonus)+"���С�";
                tell_object(me,"��õ���"+potential_bonus+"��Ǳ�ܣ�"+combat_exp_bonus+"��ѧ���飬"+COMBAT_D->chinese_daoxing(daoxing_bonus)+"���С�\n");
                break;          
        case 4:
                daoxing_bonus = daoxing_bonus*2/3;
                combat_exp_bonus = combat_exp_bonus*2/3;
                potential_bonus = 0;        
                //me->add("potential", potential_bonus);
                me->add("combat_exp", combat_exp_bonus);
                me->add("daoxing", daoxing_bonus);
                //str = "�õ���"+potential_bonus+"��Ǳ�ܣ�";
                str =combat_exp_bonus+"��ѧ���飬";
                str += COMBAT_D->chinese_daoxing(daoxing_bonus)+"���С�";
                tell_object(me,"��õ���"+combat_exp_bonus+"��ѧ���飬"+COMBAT_D->chinese_daoxing(daoxing_bonus)+"���С�\n");
                break;        
        }
        me->add("weiwang",3+random(3));
              
        str = "�����һ���Ѷ�"+chinese_number(level)+"��"+kind+"������" + str;
        if ( level > 1 ) CHANNEL_D->do_channel(me, "rumor",me->name(1)+str);
        str = str + "��ʱ"+time+"��";
        MONITOR_D->report_quest_object_msg (me, str);
        MONITOR_D->mudring_log(logpath, me, str);
        
        switch (kind)
          {case "ɱ": {
                        me->add("rulaitask_log/kill_potential",potential_bonus);
                        me->add("rulaitask_log/kill_combat",combat_exp_bonus);
                        me->add("rulaitask_log/kill_daoxing",daoxing_bonus);
                
                        switch (level)
                            {case 1:{me->add("rulaitask_log/kill1",1);
                                     break;
                                     }
                              case 2:{me->add("rulaitask_log/kill2",1);
                                      break;
                                     }
                              case 3: me->add("rulaitask_log/kill3",1);
                             }
                         break;
                      }
          case "��": {
                        me->add("rulaitask_log/arrest_potential",potential_bonus);
                        me->add("rulaitask_log/arrest_combat",combat_exp_bonus);
                        me->add("rulaitask_log/arrest_daoxing",daoxing_bonus);
                
                        switch (level)
                            {case 1:{me->add("rulaitask_log/arrest1",1);
                                     break;
                                     }
                              case 2:{me->add("rulaitask_log/arrest2",1);
                                      break;
                                     }
                              case 3: me->add("rulaitask_log/arrest3",1);
                             }
                         break;
                      }
          case "Ȱ": {
                        me->add("rulaitask_log/persuade_potential",potential_bonus);
                        me->add("rulaitask_log/persuade_combat",combat_exp_bonus);
                        me->add("rulaitask_log/persuade_daoxing",daoxing_bonus);
                
                        switch (level)
                            {case 1:{me->add("rulaitask_log/persuade1",1);
                                     break;
                                     }
                              case 2:{me->add("rulaitask_log/persuade2",1);
                                      break;
                                     }
                              case 3: me->add("rulaitask_log/persuade3",1);
                             }
                         break;
                      }
          case "��": {
                        me->add("rulaitask_log/fight_potential",potential_bonus);
                        me->add("rulaitask_log/fight_combat",combat_exp_bonus);
                        me->add("rulaitask_log/fight_daoxing",daoxing_bonus);
                
                        switch (level)
                            {case 1:{me->add("rulaitask_log/fight1",1);
                                     break;
                                     }
                              case 2:{me->add("rulaitask_log/fight2",1);
                                      break;
                                     }
                              case 3: me->add("rulaitask_log/fight3",1);
                             }
                     }                        
          }
}                               


int do_halt()
{
        object me = this_player();

        if(me->query_temp("last_halt_time") && !wizardp(me) && (me->query_temp("last_halt_time")+20)>time())
        {
                tell_object(me,"�ȵ�......\n");
                return 1;
        }
        me->add_busy(3);
        me->add("sen",-10);
        me->set_temp("last_halt_time",time());
        if (me->query_temp("zuochan"))
        {
//363                  remove_call_out("check_zuochan");
                me->delete_temp("zuochan_time");
                message_vision("$N��������˿�����վ��������\n",me);
                me->delete_temp("no_move");
                me->delete_temp("zuochan");
                return 1;
        }
        else return 0;
}       
        


string chinese_time(int timep)
{
        int t, d, h, m, s;
        string time;
        t = timep;
        s = t % 60;             t /= 60;
        m = t % 60;             t /= 60;
        h = t % 24;             t /= 24;
        d = t;

        if(d) time = chinese_number(d) + "��";
        else time = "";

        if(h) time += chinese_number(h) + "Сʱ";
        if(m) time += chinese_number(m) + "��";
        time += chinese_number(s) + "��";
        
        return time;
}


