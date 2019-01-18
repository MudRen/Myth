// find.c
// cglaem...01/25/97.

#include <skill.h>
#include <ansi.h>

inherit F_CLEAN_UP;

void fail(object me);
void find_result(object me, object env, string target);

mapping maps=([]);
void create() 
{ 
   string filename="/adm/daemons/find.map";
   string buf, *buf1;
   string dir, name;
   int size, i;

    seteuid(getuid());
   maps=([]);

   buf=read_file(filename);
   if(!buf) return; //no data available.

   buf1=explode(buf,"\n");
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
}

int main(object me, string target)
{
    	object ob, env=environment(me);
        int mana_cost;

        if (me->is_busy() || me->is_fighting() )
        return notify_fail("��������æ���ء�\n");

        if(env->query("no_fight") || env->query("no_magic") )
	  return notify_fail("��ȫ���ڲ���������ͨ��\n");

        if( !target) return notify_fail("����������ͨ��˭��\n");
	
	if((int)me->query("daoxing")<5000)
         	return notify_fail("��ĵ��в������ò�������ͨ��\n");

        if((int)me->query("sen") < 100||
	  (int)me->query("sen")*100/(int)me->query("max_sen")<50 )
  	return notify_fail("������ͷ�����ͣ��������Լ������ﶼ�������\n");

if((int)me->query_temp("find_time")> time())
 return notify_fail("ǧ���۶�����з��ˡ�Ъһ����ɡ�\n");

//	mana_cost=-(100-(int)me->query_skill("spells"))/4-40;
//	mana_cost=-100+(int)me->query_skill("spells")/10;
//      if(mana_cost > -50) mana_cost=-50;

        mana_cost=-60;

        if((int)me->query("mana")+mana_cost <= 30 )  
	  return notify_fail("��ķ����������ò�������ͨ��\n");

        me->add("mana", mana_cost);
	
     me->set_temp("find_time",time()+1);
	message_vision(HIY
	"$N�������˼������ģ�����ͻȻ����һ�������һ����ǧ���ۺ��ڣ���\n"
	NOR,me);

	call_out("find_result",2+random(3),me,env,target);
	return 1;

}

void fail(object me)
{
	tell_object(me,"ǧ���۸����㣺��֣��Ҳ�������ˣ�����\n");
	return;
}

void find_result(object me, object env, string target)
{
        object ob, where, bang;
	string fail, msg, filename, filename1, answer;
	int len;

        if(!me) return;
	if(environment(me)!=env) return;

	message_vision(HIY
	"ֻ���ٺټ�����Ц����֪�����������һ����������ļһ��$N���ߵ���˵�˼��仰��\n" NOR, me);
        
	ob = find_player(target);
	if( !ob ) ob = find_living(target);

	if (!ob || (ob->query("env/invisibility") && wizardp(ob) )) 
	  return fail(me);
	where = environment(ob);
	if (!where) return fail(me);
		//here is modified by vikee
        if(present("jin gu bang", ob) ){
	  tell_object(me,
		  "ǧ���۸����㣺�����ҵ��ˣ�����˵���ã�����˵������\n"+
		  "�Ǽһ���ź��Ӹ����Ľ𹿰���\n");
          return;
        }
	//added by weiqi, need better solution later...

	answer=MISC_D->find_place(where);
	if(!answer || sizeof(answer)<2) return fail(me);

	tell_object(me,"ǧ���۸����㣺"+(string)ob->name()+
	  "("+(string)ob->query("id")+")"+
	  "��"+answer+"��\n");

        message_vision("$N�������������һ�����˸����磬����������ü��\n",
	  ob);
        msg="�㼱æ��ָ��ȥ��";
        if(ob->query("daoxing")>me->query("daoxing")/3)
	  msg+="�ƺ�"+me->name()+"("+me->query("id")+")"+
	       "����̽��������١�\n";
        else
	  msg+="����ȴֻ��һƬãȻ��\n";
        tell_object(ob, msg);

	return;
}

int help(object me)
{
        write(@HELP
ָ���ʽ : find <ĳ��>

����ͨ���������ֱ������ڵء�
HELP
        );
        return 1;
}
