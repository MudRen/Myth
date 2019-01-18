// natured.c
//
// this code copy from hellcode
// added some job for sjsh mud
// modify by mudring May/10/2002

#pragma optimize
#pragma save_binary

#include <ansi.h>
#include <localtime.h>

#define YAOGUAI "/d/quest/baoshi/yaoguai"
#define FEIZEI "/d/quest/baoshi/feizei2"
#define REMEMBER_CHAR           '#'
#define GAME_TIME(t)            (t - 971000000)
#define DATE_SCALE              365

static int current_day_phase = -1;
mapping *day_phase;

mapping *read_table(string file);

void select_day_phase();

mixed *query_localtime(int t)
{
        mixed *lt;

        t = GAME_TIME(t);
        if (t < 1) t = 1;
        lt = localtime((t % 86400) * 365);
        lt[LT_MON];
        lt[LT_YEAR] = t / 86400;
        return lt;
}

int query_hour()        { return query_localtime(time())[LT_HOUR]; }
int query_day()         { return query_localtime(time())[LT_MDAY]; }
int query_month()       { return query_localtime(time())[LT_MON] + 1; }
int query_year()        { return query_localtime(time())[LT_YEAR]; }

void create()
{
        day_phase = read_table("/adm/etc/nature/day_phase");
        select_day_phase();
}

void update_day_phase()
{
        string msg;

        msg = color_filter(HIR"��"HIG"������ɫ"HIR"��"NOR + day_phase[current_day_phase]["outcolor"] +
                           day_phase[current_day_phase]["time_msg"] + "\n" NOR);
        message("outdoor:vision", msg, users());
        if (! undefinedp(day_phase[current_day_phase]["event_fun"]))
                call_other(this_object(), day_phase[current_day_phase]["event_fun"]);
}

void select_day_phase()
{
        mixed *lt;
        int i, t, n;

        remove_call_out("select_day_phase");

        // Get minutes of today.
        lt = query_localtime(time());
        lt[LT_MON]++;
        t = lt[LT_HOUR];

        // Find the day phase for now.
        for (i = 0; i < sizeof(day_phase) - 1; i++)
                if (t < day_phase[i + 1]["hour"]) break;

        if (i >= sizeof(day_phase) - 1)
        {
                // the last hour
                n = 24 - t;
                i = 0;
        } else
                n = day_phase[i + 1]["hour"] - t;

        // calculate the call out time
        n = n * 60 - lt[LT_MIN];
        n = n * 60 / 365 + 1;
        if (n < 1) n = 1;
        call_out("select_day_phase", n);

        if (i != current_day_phase)
        {
                current_day_phase = i;
                update_day_phase();
        }
}


void event_morning()
{
        object badguy;
        object room;
/*
        if (random(12) == 1)
        {
                if(objectp(room=load_object("/d/death/walk3")) && 
                objectp(badguy = new(YAOGUAI)))
                badguy->move(room);
                badguy->command("job �������Ҽ��������ˣ�");
                message_job( "Ԫʼ����"HIW + "���ܵظ�"HIM + "���ճ��й���ʧ��,����������Ϊ��");
        }
        if (random(12) == 2)
        {
                if(objectp(room=load_object("/d/qujing/wuzhuang/gate")) && 
                objectp(badguy = new(YAOGUAI)))
                badguy->move(room);
                badguy->command("job �����е����,�ҵ������磡");
                message_job( "Ԫʼ����"HIW + "��ׯ��"HIM + "���ճ��е�ͯʧ��,����������Ϊ��");
        }
        if (random(12) == 3)
        {
                if(objectp(room=load_object("/d/jjf/side_keting")) && 
                objectp(badguy = new(YAOGUAI)))
                badguy->move(room);
                badguy->command("job �ø�����,��Ȼ�����ҵ����£�");
                message_job( "Ԫʼ����"HIW + "������"HIM + "���ճ���ʿ��ʧ��,����������Ϊ��");
        }
        if (random(12) == 4)
        {
                if(objectp(room=load_object("/d/moon/huilang")) && 
                objectp(badguy = new(YAOGUAI)))
                badguy->move(room);
                badguy->command("job ��˵�¹����ش�����������");
                message_job( "Ԫʼ����"HIW + "�㺮��"HIM + "���ճ�����Ůʧ��,����������Ϊ��");
        }
        if (random(12) == 5)
        {
                if(objectp(room=load_object("/d/city/center")) && 
                objectp(badguy = new(YAOGUAI)))
                badguy->move(room);
                badguy->command("job ��˵���ƻʹ����ﲻ��?");
                message_job( "Ԫʼ����"HIW + "���ƻʹ�"HIM + "���ճ����鱦ʧ��,����������Ϊ��");
        }
        if (random(12) == 6)
        {
                if(objectp(room=load_object("/d/nanhai/road11")) && 
                objectp(badguy = new(YAOGUAI)))
                badguy->move(room);
                badguy->command("job ��ͷ���������������,���Ҽ������г��ȳ��ȣ�");
                message_job( "Ԫʼ����"HIW + "�Ϻ�����"HIM + "���ճ���ɮ��ʧ��,����������Ϊ��");
        }
        if (random(12) == 7)
        {
                if(objectp(room=load_object("/d/xueshan/shanpo")) && 
                objectp(badguy = new(YAOGUAI)))
                badguy->move(room);
                badguy->command("job ���첻С�İ��̴Ӹ�����,���Σ�");
                message_job( "Ԫʼ����"HIW + "��ѩɽ"HIM + "���ճ�������ʧ��,����������Ϊ��");
        }
        if (random(12) == 8)
        {
                if(objectp(room=load_object("/d/shushan/shanjiao")) && 
                objectp(badguy = new(YAOGUAI)))
                badguy->move(room);
                badguy->command("job ��ɽ���Ǽ���С��ͯü��Ŀ���,�����������ˣ�");
                message_job( "Ԫʼ����"HIW + "��ɽ"HIM + "���ճ��н�ͯʧ��,����������Ϊ��");
        }
        if (random(12) == 9)
        {
                if(objectp(room=load_object("/d/qujing/wudidong/square2")) && 
                objectp(badguy = new(YAOGUAI)))
                badguy->move(room);
                badguy->command("job ������Ҫȥ�μ�ţħ���Ĵ���,��ץ����С��������棡");
                message_job( "Ԫʼ����"HIW + "�޵׶�"HIM + "���ճ���С��ʧ��,����������Ϊ��");
        }
        if (random(12) == 10)
        {
                if(objectp(room=load_object("/d/qujing/wuji/shandao5")) && 
                objectp(badguy = new(YAOGUAI)))
                badguy->move(room);
                badguy->command("job ǰ�����,���˼�������,����");
                message_job( "Ԫʼ����"HIW + "���ƶ�"HIM + "���ճ��н���ʧ��,����������Ϊ��");
        }
        if (random(12) == 11)
        {
                if(objectp(room=load_object("/d/lingtai/baixi")) && 
                objectp(badguy = new(YAOGUAI)))
                badguy->move(room);
                badguy->command("job ������������,�Լ�����ʿ�ӵ���У�");
                message_job( "Ԫʼ����"HIW + "����ɽ"HIM + "���ճ��е�ʿʧ��,����������Ϊ��");
        }
        if (random(12) == 0)
        {
                if(objectp(room=load_object("/d/sea/huilang8")) && 
                objectp(badguy = new(YAOGUAI)))
                badguy->move(room);
                badguy->command("job ������Ĺ��𲻹���,�ţ�");
                message_job( "Ԫʼ����"HIW + "��������"HIM + "���ճ��й���ʧ��,����������Ϊ��");
        }
*/
}

void event_night()
{
        object badguy;
        object room;
/*
        if (random(12) == 1)
        {
                if(objectp(room=load_object("/d/city/qinglong-e1")) && 
                objectp(badguy = new(FEIZEI)))
                badguy->move(room);
                message_job( HIW "�ٸ�ͨ�棺"HIR + "�������н�ҹ�з������У������������Ų�������Ī����");
        }
        if (random(12) == 2)
        {
                if(objectp(room=load_object("/d/kaifeng/yao3")) && 
                objectp(badguy = new(FEIZEI)))
                badguy->move(room);
                message_job( HIW "�ٸ�ͨ�棺"HIR + "������н�ҹ�з������У������������Ų�������Ī����");
        }
        if (random(12) == 3)
        {
                if(objectp(room=load_object("/d/qujing/qinfa/jiedao1")) && 
                objectp(badguy = new(FEIZEI)))
                badguy->move(room);
                message_job( HIW "�ٸ�ͨ�棺"HIR + "�շ����н�ҹ�з������У������������Ų�������Ī����");
        }
        if (random(12) == 4)
        {
                if(objectp(room=load_object("/d/qujing/fengxian/jiedao7")) && 
                objectp(badguy = new(FEIZEI)))
                badguy->move(room);
                message_job( HIW "�ٸ�ͨ�棺"HIR + "���ɿ��н�ҹ�з������У������������Ų�������Ī����");
        }
        if (random(12) == 5)
        {
                if(objectp(room=load_object("/d/qujing/zhuzi/zhuzi5")) && 
                objectp(badguy = new(FEIZEI)))
                badguy->move(room);
                message_job( HIW "�ٸ�ͨ�棺"HIR + "���Ϲ��н�ҹ�з������У������������Ų�������Ī����");
        }
        if (random(12) == 6)
        {
                if(objectp(room=load_object("/d/qujing/jisaiguo/east1")) && 
                objectp(badguy = new(FEIZEI)))
                badguy->move(room);
                message_job( HIW "�ٸ�ͨ�棺"HIR + "�������н�ҹ�з������У������������Ų�������Ī����");
        }
        if (random(12) == 7)
        {
                if(objectp(room=load_object("/d/qujing/baoxiang/bei3")) && 
                objectp(badguy = new(FEIZEI)))
                badguy->move(room);
                message_job( HIW "�ٸ�ͨ�棺"HIR + "������н�ҹ�з������У������������Ų�������Ī����");
        }
        if (random(12) == 8)
        {
                if(objectp(room=load_object("/d/qujing/wuji/estreet2")) && 
                objectp(badguy = new(FEIZEI)))
                badguy->move(room);
                message_job( HIW "�ٸ�ͨ�棺"HIR + "�ڼ����н�ҹ�з������У������������Ų�������Ī����");
        }
        if (random(12) == 9)
        {
                if(objectp(room=load_object("/d/qujing/chechi/jieshi6")) && 
                objectp(badguy = new(FEIZEI)))
                badguy->move(room);
                message_job( HIW "�ٸ�ͨ�棺"HIR + "���ٹ��н�ҹ�з������У������������Ų�������Ī����");
        }
        if (random(12) == 10)
        {
                if(objectp(room=load_object("/d/qujing/nuerguo/towna3")) && 
                objectp(badguy = new(FEIZEI)))
                badguy->move(room);
                message_job( HIW "�ٸ�ͨ�棺"HIR + "Ů�����н�ҹ�з������У������������Ų�������Ī����");
        }
        if (random(12) == 11)
        {
                if(objectp(room=load_object("/d/qujing/tianzhu/jiedao14")) && 
                objectp(badguy = new(FEIZEI)))
                badguy->move(room);
                message_job( HIW "�ٸ�ͨ�棺"HIR + "���ù��н�ҹ�з������У������������Ų�������Ī����");
        }
        if (random(12) == 0)
        {
                if(objectp(room=load_object("/d/qujing/jinping/xiaojie1")) && 
                objectp(badguy = new(FEIZEI)))
                badguy->move(room);
                message_job( HIW "�ٸ�ͨ�棺"HIR + "��ƽ���н�ҹ�з������У������������Ų�������Ī����");
        }
*/
}
void event_afternoon()
{
        object *ob_list;
        int i;  
        ob_list = children(YAOGUAI);
                for(i=0; i<sizeof(ob_list); i++) 
                if(environment(ob_list[i]))
                {
                message_vision("$N˵����������˲����ʻ�����,������\n",ob_list[i]);
                        destruct(ob_list[i]);
                }

}

void event_dawn()
{
        object *ob_list;
        int i;
        ob_list = children(FEIZEI);
                for(i=0; i<sizeof(ob_list); i++) 
                if(environment(ob_list[i]))
                {
                        message_vision("$NЦ���������ˣ�����Ҳ�����ˣ�������\n",ob_list[i]);
                        destruct(ob_list[i]);
                }
}

void event_midnight()
{
        string msg;
        int m, d;

        m = query_month();
        d = query_day();

        msg = 0;
        switch (m * 100 + d)
        {
        case  321:
                msg = HIG "�������ڵ��ˣ������������Ķ��������￪ʼ���ա�\n" NOR;
                break;
        case  622:
                msg = HIR "���������ˣ�����Խ��Խ�ȣ����е����ﶼ�쳣��Ծ��\n" NOR;
                break;
        case  923:
                msg = HIY "��Ȼ�������ˣ����һƬ��ƣ������ջ��ʱ�ڡ�\n" NOR;
                break;
        case 1222:
                msg = HIW "���Ա����ĺ���ɨ����أ������ֿ�ʼ�˼ž������ߡ�\n" NOR;
                break;
        }

        if (msg)
                message("vision", HIR"��"HIG"������ɫ"HIR"��"NOR + msg,
//118                          msg, all_interactive());
                        msg, users());

        switch(m)
        {
        //spring weather
        case 3: case 4: case 5:
                switch(random(3))
                {
                case 0:
                        day_phase = read_table("/adm/etc/nature/spring_rain");
                        break;
                case 1:
                        day_phase = read_table("/adm/etc/nature/spring_sun");
                        break;
                case 2:
                        day_phase = read_table("/adm/etc/nature/spring_wind");
                        break;
                }
                break;
        //summer weather
        case 6: case 7: case 8:
                switch(random(3))
                {
                case 0:
                        day_phase = read_table("/adm/etc/nature/summer_rain");
                        break;
                case 1:
                        day_phase = read_table("/adm/etc/nature/summer_sun");
                        break;
                case 2:
                        day_phase = read_table("/adm/etc/nature/summer_wind");
                        break;
             }
             break;
        //autumn weather
        case 9: case 10: case 11:
                switch(random(3))
                {
                case 0:
                        day_phase = read_table("/adm/etc/nature/autumn_rain");
                        break;
                case 1:
                        day_phase = read_table("/adm/etc/nature/autumn_sun");
                        break;
                case 2:
                        day_phase = read_table("/adm/etc/nature/autumn_wind");
                        break;
                }
                break;
        //winter weather
        case 12: case 1: case 2:
                switch(random(3))
                {
                case 0:
                        day_phase = read_table("/adm/etc/nature/winter_rain");
                        break;
                case 1:
                        day_phase = read_table("/adm/etc/nature/winter_sun");
                        break;
                case 2:
                        day_phase = read_table("/adm/etc/nature/winter_wind");
                        break;
                }
                break;
        default:
                day_phase = read_table("/adm/etc/nature/day_phase");
        }
}

// This is called everyday noon by update_day_phase, defined in the
// "event_fun" field in /adm/etc/nature/day_phase
void event_evening()  //Aeddy
{
        object area,who;
        mixed file,dir;
        int amount,i;
          dir=get_dir("/data/city/");
       if(!dir) return; 
 	
	for(i=0;i<sizeof(dir);i++)
      if( sscanf(dir[i], "%s.o", file) ) {
      area=new("/obj/area1.c");
      area->create(file);
      if(area->query("no_use"))
   {
      destruct(area);

      continue;
    } 

     if(area->query("owner"))  
{
amount=area->query("people")*(area->query("farm")+area->query("trade"))*area->query("tax")/1000;
if(amount <=0) return;

    who=find_player(area->query("owner"));
    if(who) {
	who->add("balance",amount);
	if(!who->save()) {
	    log_file("city_log","Failed to return "+amount+
		    " coin to "+area->query("owner")+"\n");
	    return;
	}
	log_file("city_log","pay "+amount+" to "+area->query("owner")+"\n");
 tell_object(who,HIW+BLINK+area->query("short")+"˰��"+MONEY_D->money_str(amount)+",�Ѿ�������Ļ�ͷ��\n"NOR);

    } else {
	who=new(USER_OB);
	who->set("id",area->query("owner"));
	if(!who->restore()) {
	    log_file("city_log","Failed to return "+amount+
		    " coin to "+area->query("owner")+"\n");
	    destruct(who);
	    return;
	} else {
	    who->add("balance",amount);
	    if(!who->save(1)) { // save(1) will not erase autoload.
		log_file("city_log","Failed to return "+amount+
			" coin to "+area->query("owner")+"\n");
		destruct(who);
		return;
	    } 
	    log_file("city_log","pay "+amount+" to "+area->query("owner")+"\n");
	    destruct(who);
	    }
    }

}
}
        return;
}

void event_noon()
{
        object *ob;
        int i, skill;

        ob = users();
        for(i=0; i<sizeof(ob); i++) {
                if( !environment(ob[i]) ) continue;
                if( !environment(ob[i])->query("outdoors") ) continue;
                if( !ob[i]->query("mana") ) continue;
                if( !(skill = ob[i]->query_skill("spells", 1) )) {
                        tell_object(ob[i], "�����һ����ѣ��������һ�����������ϱ��������ˡ�\n");
                        ob[i]->set("mana", 0);
                        ob[i]->receive_damage("sen", 0);
                } else if( skill < 25 ) {
                        tell_object(ob[i], "����̫��������յ������룬�������ķ�����ʼ��ʧ�ˡ�\n");
                        ob[i]->set("mana", (int)ob[i]->query("mana") * skill / 25 );
                }
        }
}

string outdoor_room_description()
{
        return color_filter(day_phase[current_day_phase]["outcolor"] + "    " +
                            day_phase[current_day_phase]["desc_msg"] + "��\n" NOR);
}

string game_time()
{
        mixed *lt;
        string *ms = ({ "��", "��", "��", "��", });

        lt = query_localtime(time());

        return sprintf("%s��%s%s��%s��%sʱ", 
                       chinese_number(lt[LT_YEAR]),
                       ms[((lt[LT_MON] + 1) % 12) / 3],
                       chinese_number(lt[LT_MON] + 1),
                       chinese_number(lt[LT_MDAY]),
                       chinese_number(lt[LT_HOUR]), );
}

int to_game_time(int t)
{
        return GAME_TIME(t);
}

mapping *read_table(string file)
{
        string *line, *field, *format;
        mapping *data;
        int i, rn, fn;

        line = explode(read_file(file), "\n");
        data = ({});
        for(i = 0; i < sizeof(line); i++)
        {
                if (line[i] == "" || line[i][0] == REMEMBER_CHAR) continue;
                if (! pointerp(field))
                {
                        field = explode(line[i], ":");
                        continue;
                }
                if (! pointerp(format))
                {
                        format = explode(line[i], ":");
                        continue;
                }
                break;
        }

        for( rn = 0, fn = 0; i < sizeof(line); i++)
        {
                if (line[i] == "" || line[i][0] == REMEMBER_CHAR ) continue;
                if (! fn) data += ({ allocate_mapping(sizeof(field)) });
                sscanf(line[i], format[fn], data[rn][field[fn]]);
                fn = (++fn) % sizeof(field);
                if (! fn) ++rn;
        }
        return data;
}

mapping *query_day_phase() { return day_phase; }
int query_current_day_phase() {return current_day_phase;} 

