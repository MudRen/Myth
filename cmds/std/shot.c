// shot.c,jjf�շ���ר��
// created 7-4-97 pickle
// modified by vikee 2000.10
// modified by bird 2004.06.23

inherit F_CLEAN_UP;

void create() { seteuid(getuid()); }

int main(object me, string arg)
{
    string targetname, fabaoname;
    object obj, *inv, target, obj2,old_env, fabao;
    int i, amount;
    mixed no_get;

    if( !wizardp(me) && environment(me)->query("no_magic") )
     return notify_fail("�����ֹ�����䡣\n");
     if( !arg ) return notify_fail("��Ҫ���������䣿\n");

    // Check if correct format is followed
    if( sscanf(arg, "%s on %s", fabaoname, targetname)>2 )
      return notify_fail("ָ���ʽ : shot <��������> [on <Ŀ��>]\n");

    // Check if both a fabao and a target is specified.
    // if so, then check 1. whether the player own's the fabao,
    // and 2. check whether the target is in the same environment.
    if( sscanf(arg, "%s on %s", fabaoname, targetname)==2 )
    {
	fabao=present(fabaoname, me);
     if(!fabao) return notify_fail("��û�� "+fabaoname+" �������䡣\n");
	target = present(targetname, environment(me));
	if (me->is_busy() && !fabao->query("no_busy"))
        return notify_fail("����һ��������û����ɣ���Ͼ��������䡣\n");
	if(!target) return notify_fail("����û�� " + targetname + "��\n");
// ȥ���������ֵ�ʹ������
    //if(target->query("taskguai")) 
    // return notify_fail("���ſ��죬���ɰɵ����˼������\n");
	if(target==me)
     return notify_fail("���Լ������䣿\n");
	
	// forbid to kill a player whose mudage <16 .here is added by vikee :P
	if(me->query("combat_exp")<50000 && userp(target))
		return notify_fail("�Լ�����û���ã�����ɱ�ˣ�\n"); //here is modified by vikee
   
	if(me->query("daoxing")<10000 && userp(target))
  		return notify_fail("�Լ�����û���ã�����ɱ�ˣ�\n");//here is modified by vikee

      return fabao->shot(targetname);
	
}
    fabao=present(arg, me);
     if(!fabao) return notify_fail("��û��" + arg +"�������䡣\n");
    if (me->is_busy() && !fabao->query("no_busy"))
     return notify_fail("����һ��������û����ɣ���Ͼ��������䡣\n");

     return fabao->shot();
}
int help(object me)
{
    write(@HELP
ָ���ʽ : shot <��������> [on <Ŀ��>]

���ָ����������һ����䣬����������ר�á�

HELP
			);
		     return 1;
		 }
