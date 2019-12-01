/*
 * One structure allocated per active
 * process. It contains all data needed
 * about the process while the
 * process may be swapped out.
 * Other per process data (user.h)
 * is swapped with the process.
 *
 * 进程
 */
struct	proc
{
	char	p_stat;
	char	p_flag;
	char	p_pri;		/* priority, negative is high 进程的优先级 */
	char	p_sig;		/* signal number sent to this process */
	char	p_uid;		/* user id, used to direct tty signals */
	char	p_time;		/* resident time for scheduling */
	char	p_cpu;		/* cpu usage for scheduling */
	char	p_nice;		/* nice for scheduling */
	int	p_ttyp;		/* controlling tty */
	int	p_pid;		/* unique process id 进程id */
	int	p_ppid;		/* process id of parent 父进程id */
	int	p_addr;		/* address of swappable image DATA段的地址。可以是在内存里，也可以是在swap里 */
	int	p_size;		/* size of swappable image (*64 bytes) DATA段的大小 */
	int	p_wchan;	/* event process is awaiting */
	int	*p_textp;	/* pointer to text structure 指向TEXT */
} proc[NPROC];

/* stat codes p_stat 的值在这里 */
#define	SSLEEP	1		/* sleeping on high priority */
#define	SWAIT	2		/* sleeping on low priority */
#define	SRUN	3		/* running */
#define	SIDL	4		/* intermediate state in process creation */
#define	SZOMB	5		/* intermediate state in process termination */
#define	SSTOP	6		/* process being traced */

/* flag codes p_flag 的值在这里 */
#define	SLOAD	01		/* in core */
#define	SSYS	02		/* scheduling process */
#define	SLOCK	04		/* process cannot be swapped */
#define	SSWAP	010		/* process is being swapped out */
#define	STRC	020		/* process is being traced */
#define	SWTED	040		/* another tracing flag */
